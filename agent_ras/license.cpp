#include "license.h"

using namespace std;

namespace YellowManagmentStudio{

    License::License():
        issued_by_server_(false),
        license_type_(0),
        max_users_all_(0),
        max_users_cur_(0),
        net_(false),
        rmngr_port_(0){}

    License::License(const std::uint8_t** p){
        Package::ReadString(p, full_name_);
        Package::ReadString(p, full_presentation_);
        Package::ReadBool(p, issued_by_server_);
        Package::ReadInt32(p, license_type_);
        Package::ReadInt32(p, max_users_all_);
        Package::ReadInt32(p, max_users_cur_);
        Package::ReadBool(p, net_);
        Package::ReadString(p, rmngr_address_);
        Package::ReadString(p, rmngr_pid_);
        Package::ReadInt32(p, rmngr_port_);
        Package::ReadString(p, series_);
        Package::ReadString(p, short_presentation_);
    }

}