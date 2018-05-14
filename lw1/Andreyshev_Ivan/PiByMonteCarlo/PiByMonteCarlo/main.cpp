#include <iostream>
#include <string>

namespace
{
	const int HELP_ARGS_COUNT = 2;
	const int PROCESS_ARGS_COUNT = 3;
}

void HandleHelpCommand(char* argv[]);
void HandleProcessCommand(char* argv[]);

int main(int argc, char* argv[])
{
	try
	{
		switch (argc)
		{
		case HELP_ARGS_COUNT:
			HandleHelpCommand(argv);
			break;

		case PROCESS_ARGS_COUNT:
			HandleProcessCommand(argv);
			break;

		default:
			throw std::invalid_argument("Invalid arguments count. Use: <program> --help");
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}

	return 0;
}

void HandleHelpCommand(char* argv[])
{
	std::string argument = argv[1];

	if (argument != "--help")
	{
		throw std::invalid_argument("Invalid argument. Use: <program> --help");
	}

	std::cout << "Calculate Pi by Monte Carlo method." << std::endl
		<< "Available commands:" << std::endl
		<< "<program> --help.................................to see all available commands" << std::endl
		<< "<program> <iterations count> <threads count>.....to run process" << std::endl;
}

void HandleProcessCommand(char* argv[])
{
	int iterationsCount;
	int threadsCount;

	try
	{
		iterationsCount = std::stoi(argv[1]);
		threadsCount = std::stoi(argv[2]);
	}
	catch (const std::exception&)
	{
		throw std::invalid_argument("Invalid number format...");
	}

	std::cout << iterationsCount << " " << threadsCount << std::endl;
}
