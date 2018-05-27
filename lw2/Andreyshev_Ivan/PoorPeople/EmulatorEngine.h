#pragma once

#include <vector>
#include <Windows.h>

#include "Guest.h"

class EmulatorEngine
{
public:
	EmulatorEngine(IReception& reception);

	void Start(std::size_t guestsCount);

private:
	static DWORD WINAPI GuestStrategy(LPVOID param);

	IReception& m_reception;
	std::vector<Guest> m_guests;
	std::vector<HANDLE> m_threads;
	CRITICAL_SECTION m_criticalSection;

};
