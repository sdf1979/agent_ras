#include "connection.h"

namespace YellowManagmentStudio{

    ConnectionShort::ConnectionShort():
        blocked_by_ls_(0),
        connected_at_(0),
        conn_id_(0),
        session_number_(0){}

    ConnectionShort::ConnectionShort(const std::uint8_t** p){
        Package::ReadUUID(p, id_);
        Package::ReadString(p, application_);
        Package::ReadInt32(p, blocked_by_ls_);
        Package::ReadInt64(p, connected_at_);
        Package::ReadInt32(p, conn_id_);
        Package::ReadString(p, host_);
        Package::ReadUUID(p, info_base_id_);
        Package::ReadUUID(p, working_process_id_);
        Package::ReadInt32(p, session_number_);
    }

}