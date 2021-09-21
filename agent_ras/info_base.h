#pragma once

#include <string>
#include <vector>
#include <boost\uuid\uuid.hpp>
#include "i_communication.h"
#include "varint.h"

namespace YellowManagmentStudio{

    class InfoBase:public ICommunication{
    public:
        InfoBase();
        InfoBase(const std::uint8_t** p);
    private:
        boost::uuids::uuid id_;
        std::int32_t date_offset_;
        std::string dbms_;
        std::string db_name_;
        std::string db_password_;
        std::string db_server_name_;
        std::string db_user_;
        std::int64_t denied_from_;
        std::string denied_message_;
        std::string denied_parameter_;
        std::int64_t denied_to_;
        std::string descr_;
        std::string locale_;
        std::string name_;
        std::string permission_code_;
        bool scheduled_jobs_denied_;
        std::int32_t security_level_;
        bool sessions_denied_;
        std::int32_t license_distribution_;
        std::string external_connection_string_;
        bool external_session_manager_required_;
        std::string securirty_profile_;
        std::string safe_mode_securirty_profile_;
        bool reserve_working_processes_;        
    };

}