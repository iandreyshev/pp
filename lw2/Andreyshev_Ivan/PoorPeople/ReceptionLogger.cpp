#include <iostream>
#include <string>
#include <fstream>

#include "ReceptionLogger.h"

ReceptionLogger::ReceptionLogger(std::ostream& output)
	: m_output(output)
{
}

void ReceptionLogger::LogBreak()
{
	m_output << std::endl;
}

void ReceptionLogger::Log(const std::string& message)
{
	m_output << message << std::endl;
}

void ReceptionLogger::LogPrice(const Price& price)
{
	m_output << "--Price--" << std::endl;

	for (const auto& priceUnit : price)
	{
		m_output << "  " << priceUnit.first
			<< " -> " << priceUnit.second << std::endl;
	}
}

void ReceptionLogger::LogJournal(const Journal& journal)
{
	m_output << "--Journal--" << std::endl;

	for (const auto& journalUnit : journal)
	{
		m_output << "  " << journalUnit.first
			<< " -> " << journalUnit.second << std::endl;
	}
}

void ReceptionLogger::LogTotalCash(std::size_t cash)
{
	m_output << "--Cash--" << std::endl
		<< "  " << cash << std::endl;
}
