#pragma once

#include <string>
#include <map>

#include "Types.h"

class IReception
{
public:
	virtual ~IReception() = default;

	virtual Price GetPrice() = 0;
	virtual bool TakeRoom(const std::string& name) = 0;
	virtual void ReturnRoom(const std::string& name) = 0;

};
