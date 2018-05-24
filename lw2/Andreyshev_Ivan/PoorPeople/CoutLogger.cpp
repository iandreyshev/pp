#include <iostream>
#include <string>

#include "CoutLogger.h"

void CoutLogger::LogPrice(const Price & price)
{
	std::cout << "--Price--" << std::endl;
	
	for (const auto& element : price)
	{
		std::cout << "  "
			<< element.first << " - " << element.second
			<< std::endl;
	}
}

void CoutLogger::LogJournal(const Journal & journal)
{
	std::cout << "--Journal--" << std::endl;

	for (const auto& element : journal)
	{
		std::cout << "  "
			<< element.first << " - " << element.second
			<< std::endl;
	}
}

void CoutLogger::LogTotalCash(std::size_t cash)
{
	std::cout << "Cash: " << cash << std::endl;
}
