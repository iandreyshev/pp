#include <random>
#include <ctime>

#include "CRandomizer.h"

namespace PiCalc
{
	CRandomizer::CRandomizer()
	{
		std::srand(static_cast<unsigned>(time(0)));
	}

	float CRandomizer::Get(float min, float max)
	{
		return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
	}
}
