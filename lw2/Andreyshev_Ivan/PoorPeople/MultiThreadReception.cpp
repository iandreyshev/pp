#include "MultiThreadReception.h"

#include <iostream>

MultiThreadReception::MultiThreadReception(IReception& reception, CRITICAL_SECTION& criticalSection)
	: m_reception(reception)
	, m_criticalSection(criticalSection)
{
}

Price MultiThreadReception::GetPrice()
{
	LockThread();
	Price result = m_reception.GetPrice();
	UnlockThread();

	return result;
}

bool MultiThreadReception::TakeRoom(const std::string& name)
{
	LockThread();
	bool result = m_reception.TakeRoom(name);
	UnlockThread();

	return result;
}

void MultiThreadReception::ReturnRoom(const std::string& name)
{
	LockThread();
	m_reception.ReturnRoom(name);
	UnlockThread();
}

void MultiThreadReception::LockThread()
{
	EnterCriticalSection(&m_criticalSection);

	std::cout << "Reception thread: LOCKED. Thread id: "
		<< GetCurrentThreadId() << std::endl;
}

void MultiThreadReception::UnlockThread()
{
	std::cout << "Reception thread: UNLOCKED. Thread id: "
		<< GetCurrentThreadId() << std::endl;

	LeaveCriticalSection(&m_criticalSection);
}
