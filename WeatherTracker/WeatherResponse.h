#pragma once
#include "Response.h"
class WeatherResponse :
    public Response
{
public:
    WeatherResponse(std::string response);
    ~WeatherResponse();
    
    std::string get_result() override;

private:
    std::string parse_json() override;
    std::string parse_xml()  override;

};

