#pragma once

#include <string>
#include <vector>
#include <boost\uuid\uuid.hpp>
#include "i_communication.h"
#include "varint.h"
#include "cluster_objects.h"
#include "port_range.h"

namespace YellowManagmentStudio{

    class WorkingServer:public ICommunication{
    public:
        WorkingServer();
        WorkingServer(const std::uint8_t** p);
    private:
        boost::uuids::uuid id_;
        std::string host_name_;
        std::uint16_t main_port_;
        std::string name_;
        bool main_server_;
        std::int64_t safe_working_processes_memory_limit_;
        std::int64_t safe_call_memory_limit_;
        std::int32_t info_bases_per_working_process_limit_;
        std::int64_t working_process_memory_limit_;
        std::int32_t connections_per_working_process_limit_;
        std::uint16_t cluster_main_port_;
        bool dedicated_managers_;
        ClusterObjects<PortRange> port_ranges_;
        std::int64_t critical_processes_total_memory_;
        std::int64_t temporary_allowed_processes_total_memory_;
        std::int64_t temporary_allowed_processes_total_memory_time_limit_;
    };

}