#pragma once

#include <string>
#include <map>

using Price = std::map<std::string, std::size_t>;

class IHotelReception
{
public:
	virtual ~IHotelReception() = 0;

	virtual Price GetPrice() = 0;
	virtual bool TakeRoom(const std::string& name, std::size_t cash) = 0;
	virtual bool ReturnRoom(const std::string& name) = 0;

};
