#include "connector.h"

using namespace std;

using namespace std;
using namespace boost::asio;

using buf_iterator = buffers_iterator<boost::asio::streambuf::const_buffers_type>;

namespace YellowManagmentStudio{

    Connector* Connector::connector_ = nullptr;
    ConnectorDestroyer Connector::destroyer_;

    ip::tcp::endpoint GetEndPoint(io_service& io_service, const string& host, uint16_t port){
        ip::tcp::resolver resolver(io_service);
        ip::tcp::resolver::query query(host, to_string(port));
        ip::tcp::resolver::iterator iter = resolver.resolve(query);
        return *iter;
    }
    
    std::pair<buf_iterator, bool> match_varint_end(buf_iterator begin, buf_iterator end){
        buf_iterator i = begin;
        while (i != end){
            if (!static_cast<bool>(*i&0b10000000)) return std::make_pair(i, true);
            ++i;
        }
        return std::make_pair(i, false);
    }

    ConnectorDestroyer::~ConnectorDestroyer() {   
        delete connector_; 
    }

    void ConnectorDestroyer::initialize(Connector* connector) {
        connector_ = connector; 
    }

    Connector* Connector::getInstance() {
        if(!connector_){
            connector_ = new Connector();
            destroyer_.initialize(connector_);    
        }
        return connector_;
    }

    void Connector::Conect(string host, uint16_t port){
        socket_ = make_unique<ip::tcp::socket>(io_service_);
        ip::tcp::endpoint endpoint = GetEndPoint(io_service_, host, port);
        
        socket_->connect(endpoint, err_);
    }

    void Connector::Send(const void* first, std::size_t size){
        write(*socket_, buffer(first, size), err_);
    }

    void Connector::Receive(void* first, std::size_t size){
        read(*socket_, buffer(first, size), err_);
    }

    vector<uint8_t> Connector::ReceiveVarint(){
        boost::asio::streambuf stream_buf;
        read_until(*socket_, stream_buf, match_varint_end);
        vector<uint8_t> buf(stream_buf.size());
        buffer_copy(buffer(buf), stream_buf.data());
        return buf;
    }

    size_t Connector::ReceiveSizePacket(){
        uint8_t start_byte;
        Receive(&start_byte, 1);

        vector<uint8_t> buf;
        for(;;){
            uint8_t byte;
            Receive(&byte, 1);
            buf.push_back(byte);
            if (!static_cast<bool>(byte&0b10000000)) break;
        }

        return varint_read(&buf[0]);
    }

    void Connector::Close(){
        if(socket_){
            socket_->shutdown(ip::tcp::socket::shutdown_receive);
            socket_->close();
            socket_ = nullptr;
        }
    }

    Connector::~Connector(){
        Close();
    }

}