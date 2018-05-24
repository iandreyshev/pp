#include <iostream>
#include <string>

#include "InputData.h"
#include "Hotel.h"
#include "MultiThreadReception.h"
#include "EmulatorEngine.h"
#include "CoutLogger.h"

InputData ReadInput();
void FillHotel(Hotel& hotel, const InputData& input);

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	try
	{
		auto logger = CoutLogger();
		auto hotel = Hotel(logger);
		auto inputData = ReadInput();

		FillHotel(hotel, inputData);

		EmulatorEngine(hotel)
			.Start(inputData.guestCount);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}

InputData ReadInput()
{
	auto read = [](const std::string& prevMessage, std::size_t& dest) {
		try
		{
			std::cout << prevMessage << std::endl;
			std::cin >> dest;
		}
		catch (std::exception)
		{
			throw std::invalid_argument("Invalid argument format. Use only size_t range.");
		}
	};

	InputData result;

	read("First room count:", result.firstRoomCount);
	read("First room cost:", result.firstRoomPrice);
	read("Second room count:", result.secondRoomCount);
	read("Second room cost:", result.secondRoomPrice);
	read("Third room count:", result.thirdRoomCount);
	read("Third room price:", result.thirdRoomPrice);
	read("Guests count:", result.guestCount);

	return result;
}

void FillHotel(Hotel& hotel, const InputData& input)
{
	hotel.InsertRoom("First room", input.firstRoomPrice, input.firstRoomCount);
	hotel.InsertRoom("Second room", input.secondRoomPrice, input.secondRoomCount);
	hotel.InsertRoom("Third room", input.thirdRoomPrice, input.thirdRoomCount);
}
