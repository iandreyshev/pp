#pragma once

#include "IGuestLogger.h"

class GuestLogger : public IGuestLogger
{
public:
	virtual void LogPrice(const Price& price) override;
	virtual void LogJournal(const Journal& journal) override;
	virtual void LogTotalCash(std::size_t cash) override;

};
