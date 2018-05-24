#pragma once
#include <Windows.h>

#include "IHotelReception.h"

class HotelMultithreadCSDecorator : public IHotelReception
{
public:
	HotelMultithreadCSDecorator(IHotelReception& reception);

	Price GetPrice() override;
	bool TakeRoom(const std::string & name, std::size_t cash) override;
	bool ReturnRoom(const std::string & name) override;

private:
	void BeginCriticalSection();
	void EndCriticalSection();

	IHotelReception& m_reception;
	static CRITICAL_SECTION m_criticalSection;

};
