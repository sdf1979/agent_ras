#include "working_server.h"

namespace YellowManagmentStudio{

    WorkingServer::WorkingServer():
        main_port_(0),
        main_server_(false),
        safe_working_processes_memory_limit_(0),
        safe_call_memory_limit_(0),
        info_bases_per_working_process_limit_(0),
        working_process_memory_limit_(0),
        connections_per_working_process_limit_(0),
        cluster_main_port_(0),
        dedicated_managers_(false),
        critical_processes_total_memory_(0),
        temporary_allowed_processes_total_memory_(0),
        temporary_allowed_processes_total_memory_time_limit_(0){}

    WorkingServer::WorkingServer(const uint8_t** p){
        Package::ReadUUID(p, id_);
        Package::ReadString(p, host_name_);
        Package::ReadUInt16(p, main_port_);
        Package::ReadString(p, name_);
        Package::ReadBool(p, main_server_);
        Package::ReadInt64(p, safe_working_processes_memory_limit_);
        Package::ReadInt64(p, safe_call_memory_limit_);
        Package::ReadInt32(p, info_bases_per_working_process_limit_);
        Package::ReadInt64(p, working_process_memory_limit_);
        Package::ReadInt32(p, connections_per_working_process_limit_);
        Package::ReadUInt16(p, cluster_main_port_);
        Package::ReadBool(p, dedicated_managers_);
        port_ranges_ = ClusterObjects<PortRange>(p);
        Package::ReadInt64(p, critical_processes_total_memory_);
        Package::ReadInt64(p, temporary_allowed_processes_total_memory_);
        Package::ReadInt64(p, temporary_allowed_processes_total_memory_time_limit_);
    }

}