#include "HotelDecorator.h"

HotelDecorator::HotelDecorator(IHotelReception& reception, CRITICAL_SECTION& criticalSection)
	: m_reception(reception)
	, m_criticalSection(criticalSection)
{
}

Price HotelDecorator::GetPrice()
{
	BeginCriticalSection();
	Price result = m_reception.GetPrice();
	EndCriticalSection();

	return result;
}

bool HotelDecorator::TakeRoom(const std::string& name)
{
	BeginCriticalSection();
	bool result = m_reception.TakeRoom(name);
	EndCriticalSection();

	return result;
}

bool HotelDecorator::ReturnRoom(const std::string& name)
{
	BeginCriticalSection();
	bool result = m_reception.ReturnRoom(name);
	EndCriticalSection();

	return result;
}

void HotelDecorator::BeginCriticalSection()
{
	EnterCriticalSection(&m_criticalSection);
}

void HotelDecorator::EndCriticalSection()
{
	LeaveCriticalSection(&m_criticalSection);
}
