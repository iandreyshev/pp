#pragma once

#include "Types.h"

class IHotelLogger
{
public:
	virtual ~IHotelLogger() = default;

	virtual void LogPrice(const Price& price) = 0;
	virtual void LogJournal(const Journal& journal) = 0;
	virtual void LogTotalCash(std::size_t cash) = 0;

};
