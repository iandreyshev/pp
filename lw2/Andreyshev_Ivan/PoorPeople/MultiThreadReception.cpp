#include "MultiThreadReception.h"

MultiThreadReception::MultiThreadReception(IHotelReception& reception, HANDLE& mutex)
	: m_reception(reception)
	, m_mutex(mutex)
{
}

Price MultiThreadReception::GetPrice()
{
	LockMutex();
	Price result = m_reception.GetPrice();
	UnlockMutex();

	return result;
}

bool MultiThreadReception::TakeRoom(const std::string& name)
{
	LockMutex();
	bool result = m_reception.TakeRoom(name);
	UnlockMutex();

	return result;
}

void MultiThreadReception::ReturnRoom(const std::string& name)
{
	LockMutex();
	m_reception.ReturnRoom(name);
	UnlockMutex();
}

void MultiThreadReception::LockMutex()
{
	m_waitResult = WaitForSingleObject(m_mutex, INFINITE);
}

void MultiThreadReception::UnlockMutex()
{
	if (m_waitResult == WAIT_OBJECT_0)
	{
		ReleaseMutex(m_mutex);
	}
}
