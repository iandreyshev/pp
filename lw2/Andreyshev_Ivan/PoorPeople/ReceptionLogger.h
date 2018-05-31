#pragma once
#include <fstream>

#include "IReceptionLogger.h"

class ReceptionLogger : public IReceptionLogger
{
public:
	ReceptionLogger(std::ostream& output);

	virtual void LogBreak() override;
	virtual void Log(const std::string& message) override;
	virtual void LogPrice(const Price& price) override;
	virtual void LogJournal(const Journal& journal) override;
	virtual void LogTotalCash(std::size_t cash) override;

private:
	std::ostream& m_output;

};
