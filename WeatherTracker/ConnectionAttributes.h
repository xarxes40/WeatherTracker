#pragma once

#include <iostream>

#include <boost/asio/ip/tcp.hpp>

class ConnectionAttributes
{
public:
	ConnectionAttributes();
	~ConnectionAttributes();

	boost::asio::io_context ioc;
	boost::asio::ip::tcp::resolver resolver;
	boost::asio::ip::tcp::socket socket;
};

