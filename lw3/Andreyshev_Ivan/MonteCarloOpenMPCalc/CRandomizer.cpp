#include <random>
#include <ctime>

#include "CRandomizer.h"

namespace PiCalc
{
	CRandomizer::CRandomizer()
	{
		std::random_device device;
		m_randomEngine = std::mt19937(device());
	}

	float CRandomizer::Get(float min, float max)
	{
		std::uniform_real_distribution<float> distribution(
			min, std::nextafter(
				max, std::numeric_limits<float>::max()
			));

		return distribution(m_randomEngine);
	}
}
