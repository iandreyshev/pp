#include "Guest.h"

#include <Windows.h>
#include <string>
#include <iostream>

namespace
{
	const int MAX_CASH = 1000;
	const int MAX_SLEEP_DURATION = 1000;
}

Guest::Guest(const std::shared_ptr<IReception>& reception)
	: m_reception(reception)
{
	m_cash = rand() % MAX_CASH;
	m_sleepDuration = rand() % MAX_SLEEP_DURATION;
}

void Guest::StartProcess()
{
	for (auto& priceUnit : m_reception->GetPrice())
	{
		if (GoToRoom(priceUnit.first, priceUnit.second))
		{
			break;
		}
	}
}

bool Guest::GoToRoom(const std::string& roomName, std::size_t cost)
{
	if (cost > m_cash)
	{
		return false;
	}

	if (m_reception->TakeRoom(roomName))
	{
		m_cash -= cost;
		m_reception->ReturnRoom(roomName);

		return true;
	}

	return false;
}
