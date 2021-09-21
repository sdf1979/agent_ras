#pragma once

#include <boost\beast\core\detail\varint.hpp>
#include <vector>

namespace YellowManagmentStudio{

    size_t varint6_size(std::size_t value);
    size_t varint6_read(const uint8_t* first);
    void varint6_write(uint8_t* first, size_t value);
    std::vector<std::uint8_t> varint6_bytes(size_t value);

    size_t varint_size(std::size_t value);
    size_t varint_read(const uint8_t* first);
    void varint_write(uint8_t* first, size_t value);
    std::vector<std::uint8_t> varint_bytes(size_t value);    

}