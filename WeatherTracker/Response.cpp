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

void Response::check_response()
{
	std::cout << this->response << std::endl;
}

