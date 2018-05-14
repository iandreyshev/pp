#include <iostream>
#include <string>
#include <random>

#include "CMonteCarloCalc.h"
#include "ProcessData.h"
#include "CMath.h"
#include "CRandomizer.h"

namespace PiCalc
{
	namespace
	{
		const int MIN_ITERATIONS_COUNT = 0;
		const int MIN_THREADS_COUNT = 1;

		DWORD WINAPI CalcPointsAction(LPVOID param)
		{
			ProcessData* processData = reinterpret_cast<ProcessData*>(param);
			CRandomizer randomizer = CRandomizer();
			CMath math = CMath();
			auto radius = 1.f;

			for (size_t i = 0; i < processData->iterationsCount; ++i)
			{
				auto x = randomizer.Get(-radius, radius);
				auto y = randomizer.Get(-radius, radius);

				if (math.HitTest(x, y, radius))
				{
					InterlockedIncrement(processData->pointsInside);
				}
			}

			return 0;
		}
	}

	CMonteCarloCalc::CMonteCarloCalc(int iterationsCount, int threadsCount)
	{
		if (iterationsCount < MIN_ITERATIONS_COUNT)
		{
			std::string message = std::string(
				"Invalid iterations count. Min count is " +
				std::to_string(MIN_ITERATIONS_COUNT));

			throw std::invalid_argument(message);
		}

		if (threadsCount < MIN_THREADS_COUNT)
		{
			std::string message = std::string(
				"Invalid threads count. Min count is " +
				std::to_string(MIN_THREADS_COUNT));

			throw std::invalid_argument(message);
		}

		m_iterationsCount = iterationsCount;
		m_threadsCount = threadsCount;
	}

	float CMonteCarloCalc::Get()
	{
		InitActions();
		InvokeActions();

		m_threads.clear();

		return 0;
	}

	void CMonteCarloCalc::InitActions()
	{
		size_t iterationsByThread = m_iterationsCount / m_threadsCount;
		size_t remainingIterations = m_iterationsCount % m_threadsCount;

		std::vector<ProcessData> processData;

		if (iterationsByThread > 0)
		{
			for (auto i = 0; i < m_threadsCount; ++i)
			{
				processData.push_back(ProcessData(iterationsByThread));
			}
		}

		for (size_t i = 0; i < remainingIterations; ++i)
		{
			if (i == remainingIterations)
			{
				break;
			}

			if (processData.size() <= i)
			{
				processData.push_back(ProcessData(1));
			}
			else
			{
				processData[i].iterationsCount++;
			}
		}
	}

	void CMonteCarloCalc::InvokeActions()
	{
	}
}
