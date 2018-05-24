#include <time.h>

#include "EmulatorEngine.h"
#include "MultiThreadReception.h"
#include "Hotel.h"

EmulatorEngine::EmulatorEngine(IHotelReception& reception)
	: m_reception(reception)
{
	InitializeCriticalSection(&m_criticalSection);
	srand(0);
}

void EmulatorEngine::Start(std::size_t guestsCount)
{
	for (std::size_t i = 0; i < guestsCount; ++i)
	{
		auto reception = MultiThreadReception(m_reception, m_criticalSection);
		auto guest = Guest(reception);

		m_guests.push_back(guest);
	}

	for (auto& guest : m_guests)
	{
		auto guestThread = CreateThread(NULL, 0, GuestStrategy, &guest, 0, 0);
		m_threads.push_back(guestThread);
	}

	WaitForMultipleObjects(DWORD(m_threads.size()), m_threads.data(), true, INFINITE);

	m_guests.clear();
	m_threads.clear();
}

DWORD WINAPI EmulatorEngine::GuestStrategy(LPVOID param)
{
	reinterpret_cast<Guest*>(param)->StartProcess();
	return 0;
}
