#pragma once

#include <vector>
#include "varint.h"

namespace YellowManagmentStudio{

    template <class T>
    class ClusterObjects{
    public:
        ClusterObjects(){}
        ClusterObjects(const std::uint8_t** p){
            std::size_t size = varint_read(*p);
            *p += varint_size(size);
            for(std::size_t i = 0; i < size; ++i){
                cluster_objects_.push_back(T(p));
            }
        }
        T& operator[](std::size_t index){ return cluster_objects_[index]; }
        typename std::vector<T>::iterator begin() { return cluster_objects_.begin(); }
        typename std::vector<T>::iterator end(){ return cluster_objects_.end(); }
    private:
        std::vector<T> cluster_objects_;
    };

}