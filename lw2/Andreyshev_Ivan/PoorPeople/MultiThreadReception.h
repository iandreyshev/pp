#pragma once

#include <Windows.h>

#include "IHotelReception.h"

class MultiThreadReception : public IHotelReception
{
public:
	MultiThreadReception(IHotelReception& reception, CRITICAL_SECTION& criticalSection);

	Price GetPrice() override;
	bool TakeRoom(const std::string & name) override;
	bool ReturnRoom(const std::string & name) override;

private:
	void BeginCriticalSection();
	void EndCriticalSection();

	IHotelReception& m_reception;
	CRITICAL_SECTION& m_criticalSection;

};
