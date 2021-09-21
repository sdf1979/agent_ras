#include "agent_ras.h"

using namespace std;
using namespace boost::asio;

using buf_iterator = buffers_iterator<boost::asio::streambuf::const_buffers_type>;

namespace YellowManagmentStudio{

    AgentRas::AgentRas(string host, uint16_t port):
        host_(host),
        port_(port),
        connector_(nullptr){}

    bool AgentRas::Connect(){
        if(!connector_){
            connector_ = Connector::getInstance();
            connector_->Conect(host_, port_);
        }

        Package package({0x1c, 0x53, 0x57, 0x50, 0x01, 0x00, 0x01, 0x00});
        connector_->Send(package.c_str(), package.Size());
        
        package.Clear();
        package.Add(vector<uint8_t>({0x01, 0x16, 0x01}));
        package.Add("connect.timeout");
        package.Add(static_cast<std::int32_t>(2000));
        connector_->Send(package.c_str(), package.Size());
        
        vector<uint8_t> answer(connector_->ReceiveSizePacket());
        connector_->Receive(&answer[0], answer.size());

        package.Clear();
        package.Add("v8.service.Admin.Cluster");
        package.Add("10.0");
        package.Add(Package::END);
        Package package_size =Package::CreatePackageLength(package, 0x0b);
        
        connector_->Send(package_size.c_str(), package_size.Size());
        connector_->Send(package.c_str(), package.Size());
        
        answer.resize(connector_->ReceiveSizePacket());
        connector_->Receive(&answer[0], answer.size());

        return true;
    }

    void AgentRas::RequestClusterData(){
        vector<uint8_t> info = SendPackage(0x0b);
        const uint8_t* p = &info[0];

        p += 5; //Пропускаем 4 байта начала пакета 0x01 0x00 0x00 0x01 и один байт тип пакета
        clusters_ = ClusterObjects<Cluster>(&p);
    }

    void AgentRas::Close(){
        if(connector_){
            connector_->Close();
            connector_ = nullptr;
        }
    }

}