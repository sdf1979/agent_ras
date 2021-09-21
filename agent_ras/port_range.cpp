#include "port_range.h"

using namespace std;

namespace YellowManagmentStudio{

    PortRange::PortRange():
        high_bound_(0),
        low_bound_(0){}

    PortRange::PortRange(const std::uint8_t** p){
        Package::ReadUInt16(p, high_bound_);
        Package::ReadUInt16(p, low_bound_);
    }

}