#include "cluster_user.h"

namespace YellowManagmentStudio{

    ClusterUser::ClusterUser():
        password_auth_allowed_(false),
        sys_auth_allowed_(false){}

    ClusterUser::ClusterUser(const std::uint8_t** p){
        Package::ReadString(p, name_);
        Package::ReadString(p, descr_);
        Package::ReadString(p, password_);
        Package::ReadBool(p, password_auth_allowed_);
        Package::ReadBool(p, sys_auth_allowed_);
        Package::ReadString(p, sys_user_name_);
    }

}