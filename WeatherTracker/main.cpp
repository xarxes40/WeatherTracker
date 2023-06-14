#include <iostream>

#include "Request.h"

int main() 
{
	setlocale(LC_ALL, "rus");

	std::unique_ptr<Request> coord_req{ std::make_unique<Request>(Request("Заглушка/asdf")) };
	std::unique_ptr<Request> weather_request{ std::make_unique<Request>(Request("api.openweathermap.org/scripts/XML_daily.asp")) };
	
	return 0;
	
}

