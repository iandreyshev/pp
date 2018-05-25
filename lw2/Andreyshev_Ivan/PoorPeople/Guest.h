#pragma once

#include <memory>

#include "IHotelReception.h"

class Guest
{
public:
	Guest(const std::shared_ptr<IHotelReception>& reception);

	void StartProcess();

private:
	bool GoToRoom(const std::string& roomName, std::size_t cost);

	std::shared_ptr<IHotelReception> m_reception;
	std::size_t m_cash;
	int m_sleepDuration;
	std::string m_name;

};
