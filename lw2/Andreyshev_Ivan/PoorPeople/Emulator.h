#pragma once

#include <vector>

#include "Guest.h"

class Emulator
{
public:
	Emulator(std::size_t guestCount);

	void Start();

private:
	std::vector<Guest> m_guests;

};
