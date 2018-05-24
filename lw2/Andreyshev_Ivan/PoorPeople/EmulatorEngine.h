#pragma once

#include <vector>
#include <Windows.h>

#include "Guest.h"

class EmulatorEngine
{
public:
	EmulatorEngine(IHotelReception& reception);

	void Start(std::size_t guestsCount);

private:
	static DWORD WINAPI GuestStrategy(LPVOID param);

	CRITICAL_SECTION m_criticalSection;
	IHotelReception& m_reception;
	std::vector<Guest> m_guests;
	std::vector<HANDLE> m_threads;

};
