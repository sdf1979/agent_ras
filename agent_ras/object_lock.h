#pragma once

#include <string>
#include <boost\uuid\uuid.hpp>
#include "i_communication.h"

namespace YellowManagmentStudio{

    class ObjectLock:public ICommunication{
    public:
        ObjectLock();
        ObjectLock(const std::uint8_t** p);
    private:
        boost::uuids::uuid connection_id_;
        std::string lock_descr_;
        std::int64_t locked_at_;
        boost::uuids::uuid object_;
        boost::uuids::uuid sid_;
    };

}