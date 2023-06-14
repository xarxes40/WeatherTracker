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
	Request();
	Request(std::string api); // Распарсить строку (реализовать)
	~Request();
	
	void set_api(std::string api); // Распарсить строку (как в конструкторе)
	std::string get_api();

	std::string get_response();

private:
	void send_request();
	std::string read_response();

private:
	std::string host;
	std::string target;
	ConnectionAttributes* attrs;
};

