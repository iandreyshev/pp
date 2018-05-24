#pragma once

#include <string>
#include <map>

#include "Types.h"

class IHotelReception
{
public:
	virtual ~IHotelReception() = default;

	virtual Price GetPrice() = 0;
	virtual bool TakeRoom(const std::string& name) = 0;
	virtual bool ReturnRoom(const std::string& name) = 0;

};
