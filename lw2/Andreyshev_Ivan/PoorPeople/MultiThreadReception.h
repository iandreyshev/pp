#pragma once

#include <Windows.h>

#include "IReception.h"

class MultiThreadReception : public IReception
{
public:
	MultiThreadReception(IReception& reception, CRITICAL_SECTION& criticalSection);

	Price GetPrice() override;
	bool TakeRoom(const std::string& name) override;
	void ReturnRoom(const std::string& name) override;

private:
	void LockThread();
	void UnlockThread();

	CRITICAL_SECTION& m_criticalSection;
	IReception& m_reception;

};
