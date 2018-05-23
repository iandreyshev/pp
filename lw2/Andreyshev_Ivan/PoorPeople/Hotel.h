#pragma once

#include <string>
#include <vector>
#include <map>

#include "IHotelReception.h"

class Hotel : IHotelReception
{
public:
	void InsertRoom(std::string name, size_t price);

	Price GetPrice() override;
	bool TakeRoom(std::string roomKey) override;
	bool ReturnRoom(std::string roomKey) override;

private:

};
