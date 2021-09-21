#pragma once

#include <boost\asio.hpp>
#include <vector>
#include "varint.h"

namespace YellowManagmentStudio{

    class Connector;

    class ConnectorDestroyer{
    private:
        Connector* connector_;
    public:    
        ~ConnectorDestroyer();
        void initialize(Connector* logger);
    };

    class Connector{
    private:
        static Connector* connector_;
        static ConnectorDestroyer destroyer_;
        boost::asio::io_service io_service_;
        std::unique_ptr<boost::asio::ip::tcp::socket> socket_;
        boost::system::error_code err_;        
    protected: 
        Connector() {}
        Connector(const Connector&);
        Connector& operator=(Connector&);
        ~Connector();
        friend class ConnectorDestroyer;
    public:
        static Connector* getInstance();
        void Conect(std::string host, std::uint16_t port);
        void Send(const void* first, std::size_t size);
        void Receive(void* first, std::size_t size);
        std::vector<std::uint8_t> ReceiveVarint();
        std::size_t ReceiveSizePacket();
        void Close();
    };

}