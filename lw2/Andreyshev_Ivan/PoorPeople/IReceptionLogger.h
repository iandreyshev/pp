#pragma once

#include "Types.h"

class IReceptionLogger
{
public:
	virtual ~IReceptionLogger() = default;

	virtual void LogBreak() = 0;
	virtual void Log(const std::string& message) = 0;
	virtual void LogPrice(const Price& price) = 0;
	virtual void LogJournal(const Journal& journal) = 0;
	virtual void LogTotalCash(std::size_t cash) = 0;

};
