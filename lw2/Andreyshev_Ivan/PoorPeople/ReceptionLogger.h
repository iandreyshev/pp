#pragma once

#include "IReceptionLogger.h"

class ReceptionLogger : public IReceptionLogger
{
public:
	virtual void LogBreak() override;
	virtual void LogPrice(const Price& price) override;
	virtual void LogJournal(const Journal& journal) override;
	virtual void LogTotalCash(std::size_t cash) override;
	virtual void LogRoomReturn(const std::string roomName) override;

};
