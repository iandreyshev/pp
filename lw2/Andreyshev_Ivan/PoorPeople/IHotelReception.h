#pragma once

#include <string>
#include <map>

using Price = std::map<std::string, size_t>;

class IHotelReception
{
public:
	virtual ~IHotelReception() = 0;

	virtual Price GetPrice() = 0;
	virtual bool TakeRoom(std::string roomKey) = 0;
	virtual bool ReturnRoom(std::string roomKey) = 0;

};
