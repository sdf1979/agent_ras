#include "varint.h"

namespace YellowManagmentStudio{

    size_t varint6_size(std::size_t value){
        size_t n = 1;
        while(value > 63){
            ++n;
            value /= 64;
        }
        return n;
    }

    size_t varint6_read(const uint8_t* first){
        std::size_t value = 0;
        std::size_t factor = 1;
        while((*first & 0x40) != 0)
        {
            value += (*first++ & 0x3f) * factor;
            factor *= 64;
        }
        value += *first++ * factor;
        return value;
    }

    void varint6_write(uint8_t* first, size_t value){
        while(value > 63)
        {
            *first++ = static_cast<uint8_t>(0x40 | value);
            value /= 64;
        }
        *first++ = static_cast<uint8_t>(value);
    }

    std::vector<uint8_t> varint6_bytes(size_t value){
        std::vector<uint8_t> bytes(varint6_size(value));
        varint6_write(&bytes[0], value);
        return bytes;
    }

    size_t varint_size(std::size_t value){
        return boost::beast::detail::varint_size(value);        
    }

    size_t varint_read(const uint8_t* first){
        return boost::beast::detail::varint_read<const uint8_t*>(first);
    }

    void varint_write(uint8_t* first, size_t value){
        boost::beast::detail::varint_write<uint8_t*>(first, value);
    }

    std::vector<std::uint8_t> varint_bytes(size_t value){
        std::vector<uint8_t> bytes(varint_size(value));
        varint_write(&bytes[0], value);
        return bytes;
    }

}
