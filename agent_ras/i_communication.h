#pragma once

#include <vector>
#include "package.h"
#include "connector.h"

namespace YellowManagmentStudio{

    class ICommunication{
    public:
        std::vector<std::uint8_t> SendPackage(std::uint8_t package_type) const;
        std::vector<std::uint8_t> SendPackage(const Package& package, std::uint8_t package_type) const;
    };

}