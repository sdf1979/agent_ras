#pragma once

#include <string>
#include "i_communication.h"

namespace YellowManagmentStudio{

    class ClusterUser:public ICommunication{
    public:
        ClusterUser();
        ClusterUser(const std::uint8_t** p);
    private:
        std::string name_;
        std::string descr_;
        std::string password_;
        bool password_auth_allowed_;
        bool sys_auth_allowed_;
        std::string sys_user_name_;
    };

}