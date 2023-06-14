#include <iostream>

#include "Request.h"

int main() 
{
	Request* req = new Request("api.openweathermap.org/scripts/XML_daily.asp");
	delete req;
}

