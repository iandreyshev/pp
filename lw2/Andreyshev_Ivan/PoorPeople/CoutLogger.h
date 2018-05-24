#pragma once

#include "IHotelLogger.h"

class CoutLogger : public IHotelLogger
{
public:
	virtual void LogPrice(const Price& price) override;
	virtual void LogJournal(const Journal& journal) override;
	virtual void LogTotalCash(std::size_t cash) override;

};
