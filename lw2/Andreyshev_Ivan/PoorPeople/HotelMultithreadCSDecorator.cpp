#include "HotelMultithreadCSDecorator.h"

HotelMultithreadCSDecorator::HotelMultithreadCSDecorator(IHotelReception& reception)
	: m_reception(reception)
{
}

Price HotelMultithreadCSDecorator::GetPrice()
{
	BeginCriticalSection();
	Price result = m_reception.GetPrice();
	EndCriticalSection();

	return result;
}

bool HotelMultithreadCSDecorator::TakeRoom(const std::string & name, std::size_t cash)
{
	BeginCriticalSection();
	bool result = m_reception.TakeRoom(name, cash);
	EndCriticalSection();

	return result;
}

bool HotelMultithreadCSDecorator::ReturnRoom(const std::string & name)
{
	BeginCriticalSection();
	bool result = m_reception.ReturnRoom(name);
	EndCriticalSection();

	return result;
}

void HotelMultithreadCSDecorator::BeginCriticalSection()
{
	EnterCriticalSection(&m_criticalSection);
}

void HotelMultithreadCSDecorator::EndCriticalSection()
{
	LeaveCriticalSection(&m_criticalSection);
}
