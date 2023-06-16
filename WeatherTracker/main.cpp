#include <iostream>
#include <format>

#include "Request.h"
#include "LocationResponse.h"
#include "WeatherResponse.h"

void parse_coordinates(std::string& lat, std::string& lon, std::string&& coordinates) {
	size_t separator = coordinates.find(" ");
	lat = coordinates.substr(0, coordinates.size() - separator - 1);
	lon = coordinates.substr(separator + 1);
}

int main() 
{
	setlocale(LC_ALL, "rus");

	std::string city;
	std::cout << "What city you want to check weather in?" << std::endl;
	std::cin >> city;

	Request* coord_req = new Request("geocode-maps.yandex.ru/1.x/?apikey=affad8ba-52ba-49e3-800d-723343494e5b&format=json&lang=en_RU&geocode=" + city);
	Response* coordinates = new LocationResponse(coord_req->get_response());

	std::string lat;
	std::string lon;
	parse_coordinates(lat, lon, coordinates->get_result());
	
	std::string weather_api_address = std::format("api.openweathermap.org/data/3.0/onecall?lat={}&lon={}&exclude=hourly,daily&appid=072c16a231a769aaf4a4d272fc7a285b", lat, lon);

	Request* weather_request = new Request(weather_api_address);
	Response* weather = new WeatherResponse(weather_request->get_response());

	std::cout << weather->get_result() << std::endl;


	delete coord_req;
	delete coordinates;

	delete weather_request;
	delete weather;
	return 0;
	
}

