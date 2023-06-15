#include "LocationResponse.h"

using json = nlohmann::json;

LocationResponse::LocationResponse(std::string resonse)
	: Response(response)
{
	std::cout << "LocationResponse created" << std::endl;
}

LocationResponse::~LocationResponse()
{
	std::cout << "LocationResponse deleted" << std::endl;
}


std::string LocationResponse::get_result()
{
	// Create if () to switch between json and xml
	return parse_json();
}

std::string LocationResponse::parse_json()
{
	std::string string_to_parse = std::move(std::format(R"({})", this->response));
	json response_json = json::parse(string_to_parse);
	json object = response_json["response"];
	std::string coordinates = object["GeoObjectCollection"]["featureMember"][0]["GeoObject"]["Point"]["pos"];
	
	return coordinates;

}

std::string LocationResponse::parse_xml()
{
	return "Not implemeted";
}