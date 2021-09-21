#pragma once

#include <string>
#include "i_communication.h"

namespace YellowManagmentStudio{

    class PortRange:public ICommunication{
    public:
        PortRange();
        PortRange(const std::uint8_t** p);
    private:
        std::uint16_t high_bound_;
        std::uint16_t low_bound_;   
    };

}