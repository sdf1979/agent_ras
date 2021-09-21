#pragma once

#include <boost/functional/hash.hpp>
#include <string>
#include <vector>
#include <unordered_map>
#include "package.h"
#include "cluster.h"
#include "varint.h"
#include "connector.h"
#include "i_communication.h"
#include "cluster_objects.h"

namespace YellowManagmentStudio{

    class AgentRas:public ICommunication{
    public:
        AgentRas(std::string host, std::uint16_t port);
        bool Connect();
        void Close();
        void RequestClusterData();
        const ClusterObjects<Cluster>& GetClusters() const { return clusters_; }
    private:
        Connector* connector_;
        std::string host_;
        std::uint16_t port_;

        ClusterObjects<Cluster> clusters_;
    };

}