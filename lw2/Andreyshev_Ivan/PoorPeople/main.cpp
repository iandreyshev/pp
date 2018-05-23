#include <iostream>
#include <string>

namespace
{
	const int MIN_ARGS_COUNT = 7;
}

int main(int argc, char* argv[])
{
	try
	{
		if (argc < MIN_ARGS_COUNT)
		{
			std::cout << "Invalid arguments count" << std::endl
				<< "Usage: program.exe <X> <A> <Y> <B> <Z> <C>\n";

			return 1;
		}


	}
	catch (const std::exception& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}