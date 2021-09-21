#include "object_lock.h"

namespace YellowManagmentStudio{

    ObjectLock::ObjectLock():
        locked_at_(0){}

    ObjectLock::ObjectLock(const std::uint8_t** p){
        Package::ReadUUID(p, connection_id_);
        Package::ReadString(p, lock_descr_);
        Package::ReadInt64(p, locked_at_);
        Package::ReadUUID(p, object_);
        Package::ReadUUID(p, sid_);
    }

}