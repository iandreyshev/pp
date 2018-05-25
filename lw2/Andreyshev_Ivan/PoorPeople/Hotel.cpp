#include "Hotel.h"

#include <iostream>

Hotel::Hotel(IGuestLogger& logger)
	: m_logger(logger)
{
}

void Hotel::InsertRoom(const std::string& name, std::size_t price, std::size_t count)
{
	if (m_price.find(name) != m_price.end())
	{
		m_price.erase(name);
		m_roomsCount.erase(name);
	}

	m_price[name] = price;
	m_roomsCount[name] = count;
}

Price Hotel::GetPrice()
{
	return m_price;
}

bool Hotel::TakeRoom(const std::string& name)
{
	if (!IsRoomExists(name))
	{
		return false;
	}
	else if (m_roomsCount.find(name)->second <= 0)
	{
		return false;
	}

	--m_roomsCount.at(name);
	m_totalCash += m_price.find(name)->second;

	m_logger.LogPrice(m_price);
	m_logger.LogJournal(m_roomsCount);
	m_logger.LogTotalCash(m_totalCash);

	return true;
}

void Hotel::ReturnRoom(const std::string& name)
{
	if (!IsRoomExists(name))
	{
		return;
	}

	++m_roomsCount.at(name);
}

bool Hotel::IsRoomExists(const std::string& name)
{
	return m_roomsCount.find(name) != m_roomsCount.end() &&
		m_price.find(name) != m_price.end();
}
