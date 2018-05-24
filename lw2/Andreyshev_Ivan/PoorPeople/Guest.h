#pragma once

#include <memory>

#include "IHotelReception.h"

class Guest
{
public:

private:
	void PassToHotel(Guest guest, IHotelReception* reception);

private:
	void StartProcess();

	std::shared_ptr<IHotelReception> m_reception;

};
