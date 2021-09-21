#include "working_process.h"

namespace YellowManagmentStudio{

    WorkingProcess::WorkingProcess():
        avg_back_call_time_(0),
        avg_call_time_(0),
        avg_db_call_time_(0),
        avg_lock_call_time_(0),
        avg_server_call_time_(0),
        avg_threads_(0),
        capacity_(0),
        connections_(0),
        enable_(false),
        main_port_(0),
        memory_excess_time_(0),
        memory_size_(0),
        running_(0),
        selection_size_(0),
        started_at_(0),
        use_(0),
        available_perfomance_(0),
        reserve_(false){}

    WorkingProcess::WorkingProcess(const std::uint8_t** p){
        Package::ReadUUID(p, id_);
        Package::ReadDouble(p, avg_back_call_time_);
        Package::ReadDouble(p, avg_call_time_);
        Package::ReadDouble(p, avg_db_call_time_);
        Package::ReadDouble(p, avg_lock_call_time_);
        Package::ReadDouble(p, avg_server_call_time_);
        Package::ReadDouble(p, avg_threads_);
        Package::ReadInt32(p, capacity_);
        Package::ReadInt32(p, connections_);
        Package::ReadString(p, host_name_);
        Package::ReadBool(p, enable_);
        licenses_ = ClusterObjects<License>(p);
        Package::ReadUInt16(p, main_port_);
        Package::ReadInt32(p, memory_excess_time_);
        Package::ReadInt32(p, memory_size_);
        Package::ReadString(p, pid_);
        Package::ReadInt32(p, running_);
        Package::ReadInt32(p, selection_size_);
        Package::ReadInt64(p, started_at_);
        Package::ReadInt32(p, use_);
        Package::ReadInt32(p, available_perfomance_);
        Package::ReadBool(p, reserve_);
    }

}