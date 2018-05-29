#include <iostream>
#include <string>

#include "CMonteCarloCalc.h"
#include "PiCalcResult.h"
#include "CTimer.h"

namespace
{
	const int MIN_ARGS_COUNT = 2;
}

void PrintHelp();
void HandleProcessCommand(char* argv[]);
void PrintResult(float value, float spendTime);

int main(int argc, char* argv[])
{
	try
	{
		if (argc < MIN_ARGS_COUNT)
		{
			throw std::invalid_argument("Invalid arguments count. Use: <program> --help");
		}

		HandleProcessCommand(argv);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}

void PrintHelp()
{
	std::cout << "Calculate Pi by Monte Carlo method." << std::endl
		<< "Available commands:" << std::endl
		<< "<program> --help.................................to see all available commands" << std::endl
		<< "<program> <iterations count>.....................to run process" << std::endl;
}

void HandleProcessCommand(char* argv[])
{
	int iterationsCount;

	try
	{
		std::string argument = argv[1];

		if (argument == "--help")
		{
			PrintHelp();
			return;
		}
		else
		{
			iterationsCount = std::stoi(argv[1]);
		}
	}
	catch (const std::exception&)
	{
		throw std::invalid_argument("Invalid number format...");
	}

	auto timer = PiCalc::CTimer();
	auto calc = PiCalc::CMonteCarloCalc(iterationsCount);

	timer.Start();
	auto result = calc.Get();
	auto spendTime = timer.Stop();

	PrintResult(result, spendTime.count());
}

void PrintResult(float value, float spendTimeInSec)
{
	std::cout << "Pi calculated successfully" << std::endl
		<< "Pi value: " << value << std::endl
		<< "Spend time in seconds: " << spendTimeInSec << std::endl;
}
