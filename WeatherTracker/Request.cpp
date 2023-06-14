#include "Request.h"

namespace http = boost::beast::http;


// Конструкторы и деструкторы --------------------------------------------------
Request::Request()
	: host("www.cbr.ru"), target("/scripts/XML_daily.asp"), attrs(new ConnectionAttributes())
{
    std::cout << "Client created with API: " << host + target << std::endl;
}

Request::Request(std::string api)
    : host(api.substr(0, api.find('/'))), target(api.substr(api.find('/')))
{
    std::cout << "Client created with API: " << host + target << std::endl;
}

Request::~Request()
{
    delete attrs;
    std::cout << "Client deleted" << std::endl;
}

// Открытые методы -------------------------------------------------------------------

void Request::set_api(std::string api)
{
    size_t separation_point = api.find('/');
    this->host = api.substr(0, separation_point);
    this->target = api.substr(separation_point);
}

std::string Request::get_api()
{
    return this->host + this->target;
}

std::string Request::get_response()
{
    send_request();
    std::string response = read_response();
    return response;
}

// private
// Закрытые методы -----------------------------------------------------------------------
void Request::send_request()
{
    boost::asio::connect(attrs->socket, attrs->resolver.resolve(host, "80"));
    http::request<http::string_body> req(http::verb::get, target, 11);

    // Задаём поля HTTP заголовка
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Отправляем реквест через приконекченный сокет
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


