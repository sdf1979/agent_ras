#pragma once

#include <string>
#include <vector>
#include "i_communication.h"
#include "varint.h"

namespace YellowManagmentStudio{

    class License:public ICommunication{
    public:
        License();
        License(const std::uint8_t** p);
    private:
        std::string full_name_;
        std::string full_presentation_;
        bool issued_by_server_;
        std::int32_t license_type_;
        std::int32_t max_users_all_;
        std::int32_t max_users_cur_;
        bool net_;
        std::string rmngr_address_;
        std::string rmngr_pid_;
        std::int32_t rmngr_port_;
        std::string series_;
        std::string short_presentation_;
    };

}