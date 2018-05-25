#pragma once

#include <Windows.h>

#include "IHotelReception.h"

class MultiThreadReception : public IHotelReception
{
public:
	MultiThreadReception(IHotelReception& reception, HANDLE& mutex);

	Price GetPrice() override;
	bool TakeRoom(const std::string& name) override;
	void ReturnRoom(const std::string& name) override;

private:
	void LockMutex();
	void UnlockMutex();

	IHotelReception& m_reception;
	HANDLE& m_mutex;
	int m_waitResult;
};
