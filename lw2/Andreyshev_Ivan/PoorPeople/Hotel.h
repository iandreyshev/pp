#pragma once

#include <string>
#include <vector>
#include <map>

#include "IHotelReception.h"
#include "Types.h"
#include "IGuestLogger.h"

class Hotel : public IHotelReception
{
public:
	Hotel(IGuestLogger& logger);

	void InsertRoom(const std::string& name, std::size_t price, std::size_t count);

	Price GetPrice() override;
	bool TakeRoom(const std::string& name) override;
	void ReturnRoom(const std::string& name) override;

private:
	bool IsRoomExists(const std::string& name);

	IGuestLogger& m_logger;
	Price m_price = Price();
	Journal m_roomsCount = Journal();
	std::size_t m_totalCash = 0;

};
