#pragma once

#include <memory>

#include "IReception.h"

class Guest
{
public:
	Guest(const std::shared_ptr<IReception>& reception);

	void StartProcess();

private:
	bool GoToRoom(const std::string& roomName, std::size_t cost);

	std::shared_ptr<IReception> m_reception;
	std::size_t m_sleepDuration;
	std::size_t m_cash;

};
