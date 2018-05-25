#include <iostream>
#include <string>

#include "GuestLogger.h"

void GuestLogger::LogPrice(const Price& price)
{
	std::printf("--Price--\n");
	for (const auto& keyval : price)
	{
		std::printf("    %s -> %d\n", keyval.first.c_str(), keyval.second);
	}
}

void GuestLogger::LogJournal(const Journal& journal)
{
	std::printf("--Journal--\n");
	for (const auto& keyval : journal)
	{
		std::printf("    %s -> %d\n", keyval.first.c_str(), keyval.second);
	}
}

void GuestLogger::LogTotalCash(std::size_t cash)
{
	std::printf("Cash: %ld\n", cash);
}
