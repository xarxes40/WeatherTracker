#include "WeatherResponse.h"

WeatherResponse::WeatherResponse(std::string response) 
	: Response(response)
{
    std::cout << "WeatherResponse created" << std::endl;
}

WeatherResponse::~WeatherResponse()
{
	std::cout << "WeatherResponse deleted" << std::endl;
}


std::string WeatherResponse::get_result()
{
	return parse_json();
}

std::string WeatherResponse::parse_json()
{
	return "Waiting for api key to be active";
}

std::string WeatherResponse::parse_xml()
{
	return "Not implemented";
}
