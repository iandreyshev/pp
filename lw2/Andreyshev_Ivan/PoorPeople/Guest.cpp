#include "Guest.h"

#include <Windows.h>
#include <string>
#include <iostream>

namespace
{
	const int MAX_CASH = 16000;
	const int MAX_SLEEP_DURATION = 2000;
	const int MAGIC_NUMBER = 997;
}

Guest::Guest(IHotelReception& reception)
	: m_reception(reception)
{
	m_cash = rand() % MAX_CASH;
	m_sleepDuration = rand() % MAX_SLEEP_DURATION;
	std::cout << "Create guest with cash: " << m_cash << std::endl;
	std::cout << "Create guest with sleep duration: " << m_sleepDuration << std::endl;
}

void Guest::StartProcess()
{
	for (auto const& priceUnit : m_reception.GetPrice())
	{
		if (priceUnit.second <= m_cash)
		{
			GoHotel(priceUnit.first, priceUnit.second);
			break;
		}
	}
}

void Guest::GoHotel(const std::string& roomName, std::size_t cost)
{
	if (m_reception.TakeRoom(roomName))
	{
		m_cash -= cost;
		Sleep(m_sleepDuration);
		m_reception.ReturnRoom(roomName);
	}
}
