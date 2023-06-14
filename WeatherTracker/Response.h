#pragma once

#include <iostream>
#include <string>


class Response
{
public:
	Response(std::string response);
	~Response();

	std::string get_response();
	float get_currency_value(std::string currency);

private:
	float find_currency_XML(std::string currency);
private:
	std::string response;
};

