#include <iostream>

#include "Request.h"
#include "LocationResponse.h"
#include "WeatherResponse.h"

int main() 
{
	setlocale(LC_ALL, "rus");

	std::string city;
	std::cout << "What city you want to check weather in?" << std::endl;
	std::cin >> city;

	Request* coord_req = new Request("geocode-maps.yandex.ru/1.x/?apikey=affad8ba-52ba-49e3-800d-723343494e5b&format=json&lang=en_RU&geocode=" + city);
	Response* coordinates = new LocationResponse(coord_req->get_response());

	std::string check = coordinates->get_result();

	Request* weather_request = new Request("api.openweathermap.org/scripts/XML_daily.asp");
	


	delete coord_req;
	delete coordinates;

	delete weather_request;
	return 0;
	
}

