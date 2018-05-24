#include <iostream>
#include <string>

#include "CoutLogger.h"

void CoutLogger::LogPrice(const Price& price)
{
	std::cout << "--Price--" << std::endl;
}

void CoutLogger::LogJournal(const Journal& journal)
{
	std::cout << "--Journal--" << std::endl;
}

void CoutLogger::LogTotalCash(std::size_t cash)
{
	std::cout << "Cash: " << cash << std::endl;
}
