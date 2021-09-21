#pragma once

#include <vector>
#include <array>
#include <string>
#include <boost\asio.hpp>
#include <boost\uuid\uuid.hpp>
#include <boost\uuid\uuid_io.hpp>
#include <boost\beast\core\detail\varint.hpp>
#include <boost\locale.hpp>
#include "i_communication.h"
#include "session.h"
#include "cluster_objects.h"
#include "info_base.h"
#include "working_server.h"
#include "cluster_user.h"
#include "cluster_manager.h"
#include "working_process.h"
#include "object_lock.h"
#include "connection.h"

namespace YellowManagmentStudio{

    class Cluster:public ICommunication{
    public:
        Cluster();
        Cluster(const std::uint8_t** p);
        bool Auth(const std::string& user, const std::string& pass) const;
        template<typename T1>
        void UpdateClusterObjects(std::uint8_t package_type, ClusterObjects<T1>& objects);
        void UpdateInfoBases();
        void UpdateWorkingServers();
        void UpdateClusterAdmins();
        void UpdateClusterManagers();
        void UpdateWorkingProcesses();
        void UpdateSessions();
        void UpdateObjectLock();
        void UpdateConnectionsShort();
        const boost::uuids::uuid& Id(){ return id_; }
    private:
        boost::uuids::uuid id_;
        std::int32_t terminate_problem_process_in_;
        std::string host_;
        std::int32_t restart_interval_;
        std::uint16_t ip_port_;
        std::int32_t max_memory_size_;          //deprecated
        std::int32_t max_memory_time_limit_;    //deprecated
        std::string name_;
        std::int32_t secure_connection_;
        std::int32_t fault_tolerance_level_;
        std::int32_t load_balancing_mode_;
        std::int32_t errors_count_threshold_;   //deprecated
        bool kill_problem_processes_;
        bool kill_by_memory_with_dump_;

        ClusterObjects<InfoBase> info_bases_;
        ClusterObjects<WorkingServer> working_servers_;
        ClusterObjects<ClusterUser> cluster_admins_;
        ClusterObjects<ClusterManager> cluster_managers_;
        ClusterObjects<WorkingProcess> working_processes_;
        ClusterObjects<Session> sessions_;
        ClusterObjects<ObjectLock> object_locks_;
        ClusterObjects<ConnectionShort> connections_short_;        

        friend std::ostream& operator<< (std::ostream& out, const Cluster& cluster);
        friend std::wostream& operator<< (std::wostream& wout, const Cluster& cluster);
    };

    template<typename T1>
    void Cluster::UpdateClusterObjects(std::uint8_t package_type, ClusterObjects<T1>& objects){
        Package package_data;
        package_data.Add(id_);
        std::vector<uint8_t> data = SendPackage(package_data, package_type);

        const uint8_t* p = &data[0];
        p += 5; //Пропускаем 4 байта начала пакета 0x01 0x00 0x00 0x01 и один байта тип пакета
        objects = ClusterObjects<T1>(&p);
    }

}