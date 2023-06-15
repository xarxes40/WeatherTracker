#pragma once

#include "Response.h"

class LocationResponse 
	: public Response
{
public:
	LocationResponse(std::string response);
	~LocationResponse();

	std::string get_result() override;

private:
	std::string parse_json() override;
	std::string parse_xml()  override;


};

