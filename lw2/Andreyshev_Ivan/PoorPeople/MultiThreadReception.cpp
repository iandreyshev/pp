#include "MultiThreadReception.h"

MultiThreadReception::MultiThreadReception(IHotelReception& reception, CRITICAL_SECTION& criticalSection)
	: m_reception(reception)
	, m_criticalSection(criticalSection)
{
}

Price MultiThreadReception::GetPrice()
{
	BeginCriticalSection();
	Price result = m_reception.GetPrice();
	EndCriticalSection();

	return result;
}

bool MultiThreadReception::TakeRoom(const std::string& name)
{
	BeginCriticalSection();
	bool result = m_reception.TakeRoom(name);
	EndCriticalSection();

	return result;
}

bool MultiThreadReception::ReturnRoom(const std::string& name)
{
	BeginCriticalSection();
	bool result = m_reception.ReturnRoom(name);
	EndCriticalSection();

	return result;
}

void MultiThreadReception::BeginCriticalSection()
{
	EnterCriticalSection(&m_criticalSection);
}

void MultiThreadReception::EndCriticalSection()
{
	LeaveCriticalSection(&m_criticalSection);
}
