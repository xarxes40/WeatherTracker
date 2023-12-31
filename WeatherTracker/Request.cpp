#include "Request.h"

namespace http = boost::beast::http;


// K����������� � ����������� --------------------------------------------------
Request::Request(std::string api)
    : host(api.substr(0, api.find('/'))), 
    target(api.substr(api.find('/'))), 
    attrs(new ConnectionAttributes())
{
    std::cout << "Request created with API: " << host + target << std::endl;
}

Request::~Request()
{
    delete attrs;
    std::cout << "Request deleted" << std::endl;
}

// �������� ������ -------------------------------------------------------------------
std::string Request::get_response()
{
    send_request();
    std::string response = read_response();
    return response;
}

// private
// �������� ������ -----------------------------------------------------------------------
void Request::send_request()
{
    boost::asio::connect(attrs->socket, attrs->resolver.resolve(host, "80"));
    http::request<http::string_body> req(http::verb::get, target, 11);

    // ����� ���� HTTP ���������
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // ���������� ������� ����� �������������� �����
    http::write(attrs->socket, req);
}

std::string Request::read_response()
{
    
    std::string response;
    {
        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(attrs->socket, buffer, res);
        response = boost::beast::buffers_to_string(res.body().data());
    }
    attrs->socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);

    return response;
}


