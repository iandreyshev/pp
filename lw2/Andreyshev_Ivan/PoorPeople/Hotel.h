#pragma once

#include <string>
#include <vector>
#include <map>

#include "IHotelReception.h"

using CountJournal = std::map<std::string, std::size_t>;

class Hotel : IHotelReception
{
public:
	void InsertRoom(const std::string& name, std::size_t price, std::size_t count);

	Price GetPrice() override;
	bool TakeRoom(const std::string& name, std::size_t cash) override;
	bool ReturnRoom(const std::string& name) override;

private:
	bool IsRoomExists(const std::string& name);

	Price m_price = Price();
	CountJournal m_roomsCount = CountJournal();
	std::size_t m_totalCash = 0;

};
