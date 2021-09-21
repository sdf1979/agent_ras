#include "package.h"
#include <winsock.h>

using namespace std;

#define _WS2_32_WINSOCK_SWAP_LONGLONG(l)            \
            ( ( ((l) >> 56) & 0x00000000000000FFLL ) |       \
              ( ((l) >> 40) & 0x000000000000FF00LL ) |       \
              ( ((l) >> 24) & 0x0000000000FF0000LL ) |       \
              ( ((l) >>  8) & 0x00000000FF000000LL ) |       \
              ( ((l) <<  8) & 0x000000FF00000000LL ) |       \
              ( ((l) << 24) & 0x0000FF0000000000LL ) |       \
              ( ((l) << 40) & 0x00FF000000000000LL ) |       \
              ( ((l) << 56) & 0xFF00000000000000LL ) )

namespace YellowManagmentStudio{

    uint64_t ntohll (uint64_t value){ 
        const uint64_t retval = _WS2_32_WINSOCK_SWAP_LONGLONG(value);
        return retval;
    }

    Package::Package(vector<uint8_t> data):
        data_(data){};

    Package Package::CreatePackageLength(const Package& package, uint8_t type){
        Package package_length({type});
        vector<uint8_t> bytes(varint_bytes(package.Size()));
        package_length.data_.insert(package_length.data_.end(), bytes.begin(), bytes.end());
        return package_length;
    }

    void Package::Add(const vector<uint8_t>& data){
        data_.insert(data_.end(), data.begin(), data.end());
    }

    void Package::Add(const string& data){
        vector<uint8_t> bytes(varint6_bytes(data.size()));
        data_.insert(data_.end(), bytes.begin(), bytes.end());
        
        size_t cur_size = data_.size();
        data_.resize(cur_size + data.size());
        memcpy(&data_[cur_size], data.c_str(), data.size());
    }

    void Package::Add(std::uint8_t ch){
        data_.push_back(ch);
    }

    void Package::Add(std::int32_t value){
        vector<uint8_t> bytes(varint6_bytes(sizeof(value)));
        data_.insert(data_.end(), bytes.begin(), bytes.end());
        
        value = htonl(value);
        size_t cur_size = data_.size();
        data_.resize(cur_size + sizeof(value));
        memcpy(&data_[cur_size], reinterpret_cast<char*>(&value), sizeof(value));
    }

    void Package::Add(const boost::uuids::uuid& value){
        size_t cur_size = data_.size();
        data_.resize(cur_size + value.size());
        memcpy(&data_[cur_size], &value, value.size());        
    }

    void Package::Add(const Package& package){
        data_.insert(data_.end(), package.data_.begin(),package.data_.end());
    }

    void Package::ReadUUID(const uint8_t** p, boost::uuids::uuid& value){
        memcpy(&value, *p, 16);
        *p += 16;
    }

    void Package::ReadUInt16(const std::uint8_t** p, std::uint16_t& value){
        memcpy(&value, *p, sizeof(value));
        value = ntohs(value);
        *p += sizeof(value);
    }

    void Package::ReadInt32(const std::uint8_t** p, int32_t& value){
        memcpy(&value, *p, sizeof(value));
        value = ntohl(value);
        *p += sizeof(value);
    }

    void Package::ReadInt64(const std::uint8_t** p, std::int64_t& value){
        memcpy(&value, *p, sizeof(value));
        value = ntohll(value);
        *p += sizeof(value);
    }

    void Package::ReadString(const uint8_t** p, string& value){
        size_t size_value = varint6_read(*p);
        *p += varint6_size(size_value);
        value.resize(size_value);
        mempcpy(&value[0], *p, size_value);
        *p += size_value;
    }

    void Package::ReadBool(const uint8_t** p, bool& value){
        value = **p;
        *p += 1;
    }

    void Package::ReadDouble(const std::uint8_t** p, double& value){
        memcpy(&value, *p, sizeof(value));
        
        int64_t tmp = ntohl(*reinterpret_cast<int64_t*>(&value));
        value = *reinterpret_cast<double*>(&tmp);
        *p += sizeof(value);        
    }

}