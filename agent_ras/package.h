#pragma once

#include <vector>
#include <string>
#include <boost\uuid\uuid.hpp>
#include "varint.h"

namespace YellowManagmentStudio{

    class Package{
    public:
        Package(){};
        static Package CreatePackageLength(const Package& package, std::uint8_t type = 0x0e);
        Package(std::vector<std::uint8_t> data);
        void Add(const std::vector<std::uint8_t>& data);
        void Add(const std::string& data);
        void Add(std::uint8_t ch);
        void Add(std::int32_t value);
        void Add(const boost::uuids::uuid& value);
        void Add(const Package& package);
        size_t Size() const { return data_.size(); }
        void Clear() { data_.clear(); }
        const char* c_str() const { return reinterpret_cast<const char*>(&data_[0]); }
        static const std::uint8_t END = 0x80;

        static void ReadUUID(const std::uint8_t** p, boost::uuids::uuid& value);
        static void ReadUInt16(const std::uint8_t** p, std::uint16_t& value);
        static void ReadInt32(const std::uint8_t** p, std::int32_t& value);
        static void ReadInt64(const std::uint8_t** p, std::int64_t& value);
        static void ReadString(const std::uint8_t** p, std::string& value);
        static void ReadBool(const std::uint8_t** p, bool& value);
        static void ReadDouble(const std::uint8_t** p, double& value);
    private:
        std::vector<std::uint8_t> data_;
    };

}