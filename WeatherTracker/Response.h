#pragma once

#include <iostream>
#include <string>


class Response
{
public:
	Response() = delete;
	Response(std::string response);
	virtual ~Response();

	void check_response();
	virtual std::string get_result() = 0;

private:
	virtual std::string parse_json() = 0;
private:
	std::string response;
};

