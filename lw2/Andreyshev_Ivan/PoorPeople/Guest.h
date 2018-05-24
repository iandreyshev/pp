#pragma once

#include <memory>

#include "IHotelReception.h"

class Guest
{
public:
	Guest(IHotelReception& reception);

	void StartProcess();

private:
	void GoHotel(const std::string& roomName, std::size_t cost);

	IHotelReception& m_reception;
	std::size_t m_cash;
	int m_sleepDuration;

};
