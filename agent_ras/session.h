#pragma once

#include <boost\uuid\uuid.hpp>
#include <string>
#include "i_communication.h"
#include "package.h"
#include "license.h"
#include "cluster_objects.h"

namespace YellowManagmentStudio{

    class Session:public ICommunication{
    public:
        Session();
        Session(const std::uint8_t** p);
    private:
        boost::uuids::uuid id_;
        std::string app_;
        std::int32_t blocked_by_dbms_;
        std::int32_t blocked_by_ls_;
        std::int64_t bytes_all_;
        std::int64_t bytes_last_5_min_;
        std::int32_t calls_all_;
        std::int64_t calls_last_5_min_;
        boost::uuids::uuid connection_id_;
        std::int64_t dbms_bytes_all_;
        std::int64_t dbms_bytes_last_5_min_;
        std::string db_proc_proc_info_;
        std::int32_t db_proc_took_;
        std::int64_t db_proc_took_at_;
        std::int32_t duration_all_;
        std::int32_t duration_all_dbms_;
        std::int32_t duration_current_;
        std::int32_t duration_current_dbms_;
        std::int64_t duration_last_5_min_;
        std::int64_t duration_last_5_min_dbms_;
        std::string host_;
        boost::uuids::uuid info_base_id_;
        std::int64_t last_active_at_;
        bool hibernate_;
        std::int32_t passive_session_hibernate_time_;
        std::int32_t hibernate_session_terminate_time_;
        ClusterObjects<License> licenses_;
        std::string locale_;
        boost::uuids::uuid working_process_id_;
        std::int32_t session_id_;
        std::int64_t started_at_;
        std::string user_name_;
        std::int64_t memory_current_;
        std::int64_t memory_last_5_min_;
        std::int64_t memory_total_;
        std::int64_t read_bytes_current_;
        std::int64_t read_bytes_last_5_min_;
        std::int64_t read_bytes_total_;
        std::int64_t write_bytes_current_;
        std::int64_t write_bytes_last_5_min_;
        std::int64_t write_bytes_total_; 
        std::int32_t duration_current_service_;
        std::int64_t duration_last_5_min_service_;
        std::int32_t duration_all_service_;
        std::string current_service_name_;
        std::int64_t cpu_time_current_;
        std::int64_t cpu_time_last_5_min_;
        std::int64_t cpu_time_all_;
        std::string data_separation_;
        std::string client_ip_address_;
    };

}