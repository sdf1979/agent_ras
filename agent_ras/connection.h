#pragma once

#include <string>
#include <boost\uuid\uuid.hpp>
#include "i_communication.h"

namespace YellowManagmentStudio{

    class ConnectionShort:public ICommunication{
    public:
        ConnectionShort();
        ConnectionShort(const std::uint8_t** p);
    private:
        boost::uuids::uuid id_;
        std::string application_;
        std::int32_t blocked_by_ls_;
        std::int64_t connected_at_;
        std::int32_t conn_id_;
        std::string host_;
        boost::uuids::uuid info_base_id_;
        boost::uuids::uuid working_process_id_;
        std::int32_t session_number_;
    };

}