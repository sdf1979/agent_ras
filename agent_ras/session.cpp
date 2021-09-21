#include "session.h"

using namespace std;

namespace YellowManagmentStudio{

    Session::Session():
        blocked_by_dbms_(0),
        blocked_by_ls_(0),
        bytes_all_(0),
        bytes_last_5_min_(0),
        calls_all_(0),
        calls_last_5_min_(0),
        dbms_bytes_all_(0),
        dbms_bytes_last_5_min_(0),
        db_proc_took_(0),
        db_proc_took_at_(0),
        duration_all_(0),
        duration_all_dbms_(0),
        duration_current_(0),
        duration_current_dbms_(0),
        duration_last_5_min_(0),
        duration_last_5_min_dbms_(0),
        last_active_at_(0),
        hibernate_(false),
        passive_session_hibernate_time_(0),
        hibernate_session_terminate_time_(0),
        session_id_(0),
        started_at_(0),
        memory_current_(0),
        memory_last_5_min_(0),
        memory_total_(0),
        read_bytes_current_(0),
        read_bytes_last_5_min_(0),
        read_bytes_total_(0),
        write_bytes_current_(0),
        write_bytes_last_5_min_(0),
        write_bytes_total_(0),
        duration_current_service_(0),
        duration_last_5_min_service_(0),
        duration_all_service_(0),
        cpu_time_current_(0),
        cpu_time_last_5_min_(0),
        cpu_time_all_(0){}

    Session::Session(const uint8_t** p){
        Package::ReadUUID(p, id_);
        Package::ReadString(p, app_);
        Package::ReadInt32(p, blocked_by_dbms_);
        Package::ReadInt32(p, blocked_by_ls_);
        Package::ReadInt64(p, bytes_all_);
        Package::ReadInt64(p, bytes_last_5_min_);
        Package::ReadInt32(p, calls_all_);
        Package::ReadInt64(p, calls_last_5_min_);
        Package::ReadUUID(p, connection_id_);
        Package::ReadInt64(p, dbms_bytes_all_);
        Package::ReadInt64(p, dbms_bytes_last_5_min_);
        Package::ReadString(p, db_proc_proc_info_);
        Package::ReadInt32(p, db_proc_took_);
        Package::ReadInt64(p, db_proc_took_at_);
        Package::ReadInt32(p, duration_all_);
        Package::ReadInt32(p, duration_all_dbms_);
        Package::ReadInt32(p, duration_current_);
        Package::ReadInt32(p, duration_current_dbms_);
        Package::ReadInt64(p, duration_last_5_min_);
        Package::ReadInt64(p, duration_last_5_min_dbms_);
        Package::ReadString(p, host_);
        Package::ReadUUID(p, info_base_id_);
        Package::ReadInt64(p, last_active_at_);
        Package::ReadBool(p, hibernate_);
        Package::ReadInt32(p, passive_session_hibernate_time_);
        Package::ReadInt32(p, hibernate_session_terminate_time_);
        licenses_ = ClusterObjects<License>(p);
        Package::ReadString(p, locale_);
        Package::ReadUUID(p, working_process_id_);
        Package::ReadInt32(p, session_id_);
        Package::ReadInt64(p, started_at_);
        Package::ReadString(p, user_name_);
        Package::ReadInt64(p, memory_current_);
        Package::ReadInt64(p, memory_last_5_min_);
        Package::ReadInt64(p, memory_total_);
        Package::ReadInt64(p, read_bytes_current_);
        Package::ReadInt64(p, read_bytes_last_5_min_);
        Package::ReadInt64(p, read_bytes_total_);
        Package::ReadInt64(p, write_bytes_current_);
        Package::ReadInt64(p, write_bytes_last_5_min_);
        Package::ReadInt64(p, write_bytes_total_); 
        Package::ReadInt32(p, duration_current_service_);
        Package::ReadInt64(p, duration_last_5_min_service_);
        Package::ReadInt32(p, duration_all_service_);
        Package::ReadString(p, current_service_name_);
        Package::ReadInt64(p, cpu_time_current_);
        Package::ReadInt64(p, cpu_time_last_5_min_);
        Package::ReadInt64(p, cpu_time_all_);
        Package::ReadString(p, data_separation_);
        Package::ReadString(p, client_ip_address_);
    }

}