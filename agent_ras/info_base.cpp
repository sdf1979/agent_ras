#include "info_base.h"

namespace YellowManagmentStudio{

    InfoBase::InfoBase():
        date_offset_(0),
        denied_from_(0),
        denied_to_(0),
        scheduled_jobs_denied_(false),
        security_level_(0),
        sessions_denied_(false),
        license_distribution_(0),
        external_session_manager_required_(false),
        reserve_working_processes_(false){}

    InfoBase::InfoBase(const std::uint8_t** p):
        date_offset_(0),
        denied_from_(0),
        denied_to_(0),
        scheduled_jobs_denied_(false),
        security_level_(0),
        sessions_denied_(false),
        license_distribution_(0),
        external_session_manager_required_(false),
        reserve_working_processes_(false){
        Package::ReadUUID(p, id_);
        Package::ReadString(p, descr_);
        Package::ReadString(p, name_);       
    }

}