#include "cluster_manager.h"

namespace YellowManagmentStudio{

    ClusterManager::ClusterManager():
        main_manager_(0),
        main_port_(0){}

    ClusterManager::ClusterManager(const std::uint8_t** p){
        Package::ReadUUID(p, id_);
        Package::ReadString(p, descr_);
        Package::ReadString(p, host_name_);
        Package::ReadInt32(p, main_manager_);
        Package::ReadUInt16(p, main_port_);
        Package::ReadString(p, pid_);
    }

}