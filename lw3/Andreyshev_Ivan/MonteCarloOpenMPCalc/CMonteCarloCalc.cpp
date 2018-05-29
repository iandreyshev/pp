#include <iostream>
#include <string>
#include <random>
#include <memory>

#include "CMonteCarloCalc.h"
#include "CMath.h"
#include "CRandomizer.h"

namespace PiCalc
{
	namespace
	{
		const int MIN_ITERATIONS_COUNT = 0;
	}

	CMonteCarloCalc::CMonteCarloCalc(int iterationsCount)
	{
		if (iterationsCount < MIN_ITERATIONS_COUNT)
		{
			std::string message = std::string(
				"Invalid iterations count. Min count is " +
				std::to_string(MIN_ITERATIONS_COUNT));

			throw std::invalid_argument(message);
		}

		m_iterationsCount = iterationsCount;
	}

	float CMonteCarloCalc::Get()
	{
		std::size_t innerHistCount = 0;

		#pragma omp parallel for
		for (int i = 0; i < m_iterationsCount; ++i)
		{
			CRandomizer randomizer = CRandomizer();
			const CMath& math = CMath();

			const float& radius = 1.f;
			const float& x = randomizer.Get(-radius, radius);
			const float& y = randomizer.Get(-radius, radius);

			if (math.HitTest(x, y, radius))
			{
				InterlockedIncrement(&innerHistCount);
			}
		}

		return 4.f * static_cast<float>(innerHistCount) / m_iterationsCount;
	}

}
