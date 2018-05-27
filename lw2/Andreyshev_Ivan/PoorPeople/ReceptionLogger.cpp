#include <iostream>
#include <string>

#include "ReceptionLogger.h"

void ReceptionLogger::LogBreak()
{
	std::cout << std::endl;
}

void ReceptionLogger::LogPrice(const Price& price)
{
	std::cout << "--Price--" << std::endl;

	for (const auto& priceUnit : price)
	{
		std::cout << "  " << priceUnit.first
			<< " -> " << priceUnit.second << std::endl;
	}
}

void ReceptionLogger::LogJournal(const Journal& journal)
{
	std::cout << "--Journal--" << std::endl;

	for (const auto& journalUnit : journal)
	{
		std::cout << "  " << journalUnit.first
			<< " -> " << journalUnit.second << std::endl;
	}
}

void ReceptionLogger::LogTotalCash(std::size_t cash)
{
	std::cout << "--Cash--" << std::endl
		<< "  " << cash << std::endl;
}

void ReceptionLogger::LogRoomReturn(const std::string roomName)
{
	std::cout << "--Return room--" << std::endl
		<< "  " << roomName << std::endl;
}
