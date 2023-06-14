#include "Response.h"

Response::Response(std::string response)
	:response(response)
{
	std::cout << "Response created" << std::endl;
}

Response::~Response()
{
	std::cout << "Response deleted" << std::endl;
}

std::string Response::get_response()
{
	return response;
}

float Response::get_currency_value(std::string currency)
{
	return find_currency_XML(currency);
}

float Response::find_currency_XML(std::string currency)
{
	size_t currency_pos = response.find(currency);
	size_t value_pos = response.find("Value", currency_pos);
	size_t value_begin = response.find(">", value_pos);
	size_t value_end = response.find("<", value_begin);
	size_t value_count = value_end - value_begin;
	std::string value = response.substr(value_begin + 1, value_count - 1);


	size_t nominal_pos = response.find("Nominal", currency_pos);
	size_t nominal_begin = response.find(">", nominal_pos);
	size_t nominal_end = response.find("<", nominal_begin);
	size_t nominal_count = nominal_begin - nominal_end;
	std::string nominal = response.substr(nominal_begin + 1, nominal_count - 1);

	float result = std::stof(value) / std::stof(nominal);
	
	return result;
}
