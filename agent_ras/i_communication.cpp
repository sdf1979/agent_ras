#include "i_communication.h"

using namespace std;

namespace YellowManagmentStudio{

    vector<uint8_t> Send(const Package& package_length, const Package& package_data){
        Connector* connector = Connector::getInstance();
        connector->Send(package_length.c_str(), package_length.Size());
        connector->Send(package_data.c_str(), package_data.Size());

        vector<uint8_t> answer(connector->ReceiveSizePacket());
        connector->Receive(&answer[0], answer.size());

        return answer;        
    }

    vector<uint8_t> ICommunication::SendPackage(uint8_t package_type) const{
        Package package_data({0x01, 0x00, 0x00, 0x01, package_type});
        Package package_length = Package::CreatePackageLength(package_data);
        
        return Send(package_length, package_data);
    }

    vector<uint8_t> ICommunication::SendPackage(const Package& package, uint8_t package_type) const{
        Package package_data({0x01, 0x00, 0x00, 0x01, package_type});
        package_data.Add(package);
        Package package_length = Package::CreatePackageLength(package_data);
        
        return Send(package_length, package_data);
    }

}