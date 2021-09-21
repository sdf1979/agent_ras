#pragma once

#include <string>
#include <boost\uuid\uuid.hpp>
#include "i_communication.h"
#include "cluster_objects.h"
#include "license.h"

namespace YellowManagmentStudio{

    class WorkingProcess:public ICommunication{
    public:
        WorkingProcess();
        WorkingProcess(const std::uint8_t** p);
    private:
        boost::uuids::uuid id_;
        double avg_back_call_time_;
        double avg_call_time_;
        double avg_db_call_time_;
        double avg_lock_call_time_;
        double avg_server_call_time_;
        double avg_threads_;
        std::int32_t capacity_;
        std::int32_t connections_;
        std::string host_name_;
        bool enable_;
        ClusterObjects<License> licenses_;
        std::uint16_t main_port_;
        std::int32_t memory_excess_time_;
        std::int32_t memory_size_;
        std::string pid_;
        std::int32_t running_;
        std::int32_t selection_size_;
        std::int64_t started_at_;
        std::int32_t use_;
        std::int32_t available_perfomance_;
        bool reserve_;
    };

}