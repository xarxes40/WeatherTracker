#include "ConnectionAttributes.h"

ConnectionAttributes::ConnectionAttributes()
	:resolver(boost::asio::ip::tcp::resolver(ioc)),
     socket(boost::asio::ip::tcp::socket(ioc))
{
	std::cout << "ConnectionAttributes created" << std::endl;
}

ConnectionAttributes::~ConnectionAttributes()
{
	std::cout << "ConnectionAttributes deleted" << std::endl;
}
