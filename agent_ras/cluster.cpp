#include "cluster.h"
#include <cstring>

using namespace std;
using namespace boost::beast::detail;

namespace YellowManagmentStudio{

    Cluster::Cluster():
        terminate_problem_process_in_(0),
        restart_interval_(0),
        ip_port_(0),
        max_memory_size_(0),
        max_memory_time_limit_(0),
        secure_connection_(0),
        fault_tolerance_level_(0),
        load_balancing_mode_(0),
        errors_count_threshold_(0),
        kill_problem_processes_(false),
        kill_by_memory_with_dump_(false){}

    Cluster::Cluster(const std::uint8_t** p){
        Package::ReadUUID(p, id_);
        Package::ReadInt32(p, terminate_problem_process_in_);
        Package::ReadString(p, host_);
        Package::ReadInt32(p, restart_interval_);
        Package::ReadUInt16(p, ip_port_);
        Package::ReadInt32(p, max_memory_size_);
        Package::ReadInt32(p, max_memory_time_limit_);
        Package::ReadString(p, name_);
        Package::ReadInt32(p, secure_connection_);
        Package::ReadInt32(p, fault_tolerance_level_);
        Package::ReadInt32(p, load_balancing_mode_);
        Package::ReadInt32(p, errors_count_threshold_);
        Package::ReadBool(p, kill_problem_processes_);
        Package::ReadBool(p, kill_by_memory_with_dump_);
    }

    bool Cluster::Auth(const std::string& user, const std::string& pass) const{
        Package package_data;
        package_data.Add(id_);
        if(user.size()){
            package_data.Add(user);
        }
        else{
            package_data.Add(static_cast<uint8_t>(0x00));
        }
        if(pass.size()){
            package_data.Add(pass);
        }
        else{
            package_data.Add(static_cast<uint8_t>(0x00));
        }
        
        SendPackage(package_data, 0x09);
                
        return true;        
    }

    void Cluster::UpdateInfoBases(){
        UpdateClusterObjects(0x2a, info_bases_);
    }

    void Cluster::UpdateWorkingServers(){
        UpdateClusterObjects(0x16, working_servers_);
    }

    void Cluster::UpdateClusterAdmins(){
        UpdateClusterObjects(0x02, cluster_admins_);        
    }

    void Cluster::UpdateClusterManagers(){
        UpdateClusterObjects(0x12, cluster_managers_);
    }

    void Cluster::UpdateWorkingProcesses(){
        UpdateClusterObjects(0x1d, working_processes_);
    }

    void Cluster::UpdateSessions(){
        UpdateClusterObjects(0x41, sessions_);
    }

    void Cluster::UpdateObjectLock(){
        UpdateClusterObjects(0x48, object_locks_);
    }

    void Cluster::UpdateConnectionsShort(){
        UpdateClusterObjects(0x32, connections_short_);
    }

    ostream& operator<< (std::ostream &out, const Cluster &cluster){
        out <<
        "id: " << cluster.id_ << '\n' <<
        "host: " << cluster.host_ << '\n' <<
        "port: " << cluster.ip_port_ << '\n' <<
        "name: " << cluster.name_ << '\n';
        return out;
    }

    wostream& operator<< (std::wostream &wout, const Cluster &cluster){
        wout <<
        L"id: " << cluster.id_ << '\n' <<
        L"host: " << boost::locale::conv::utf_to_utf<wchar_t, char>(cluster.host_) << '\n' <<
        L"port: " << cluster.ip_port_ << '\n' <<
        L"name: " << boost::locale::conv::utf_to_utf<wchar_t, char>(cluster.name_) << '\n';
        return wout;
    }

}
