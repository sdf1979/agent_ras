#pragma once

#include <string>
#include <boost\uuid\uuid.hpp>
#include "i_communication.h"

namespace YellowManagmentStudio{

    class ClusterManager:public ICommunication{
    public:
        ClusterManager();
        ClusterManager(const std::uint8_t** p);
    private:
        boost::uuids::uuid id_;
        std::string descr_;
        std::string host_name_;
        std::int32_t main_manager_;
        std::uint16_t main_port_;
        std::string pid_;
    };

}