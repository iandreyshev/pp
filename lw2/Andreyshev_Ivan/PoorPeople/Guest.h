#pragma once

#include <memory>

#include "IHotelReception.h"

class Guest
{
public:
	Guest(IHotelReception& hotel);

private:
	void StartProcess();

	IHotelReception& m_reception;

};
