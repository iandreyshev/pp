#include <time.h>

#include "EmulatorEngine.h"
#include "MultiThreadReception.h"
#include "Hotel.h"

EmulatorEngine::EmulatorEngine(IHotelReception& reception)
	: m_reception(reception)
{
	srand(0);
}

void EmulatorEngine::Start(std::size_t guestsCount)
{
	m_mutex = CreateMutex(NULL, FALSE, NULL);

	for (std::size_t i = 0; i < guestsCount; ++i)
	{
		auto guest = Guest(
			std::make_shared<MultiThreadReception>(m_reception, m_mutex));
		m_guests.push_back(guest);
	}

	for (auto& guest : m_guests)
	{
		auto guestThread = CreateThread(NULL, 0, GuestStrategy, &guest, 0, DWORD());
		m_threads.push_back(guestThread);
	}

	WaitForMultipleObjects(DWORD(m_threads.size()), m_threads.data(), TRUE, INFINITE);
}

DWORD WINAPI EmulatorEngine::GuestStrategy(LPVOID param)
{
	reinterpret_cast<Guest*>(param)->StartProcess();

	return 0;
}
