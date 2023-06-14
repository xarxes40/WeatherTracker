#pragma once

#include <iostream>
#include <string>

#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "ConnectionAttributes.h"


class Request
{
public:
	Request() = delete;
	Request(std::string api); 
	~Request();

	std::string get_response();

private:
	void send_request();
	std::string read_response();

private:
	std::string host;
	std::string target;
	ConnectionAttributes* attrs;
};

