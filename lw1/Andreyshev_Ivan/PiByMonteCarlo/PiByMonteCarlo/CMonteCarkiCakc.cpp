#include <iostream>
#include <string>
#include <random>

#include "CMonteCarloCalc.h"
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
			std::cout << "Data casted with iterations " << processData->iterationsCount << std::endl;

			CRandomizer randomizer = CRandomizer();
			std::cout << "Randomizer initialized" << std::endl;

			CMath math = CMath();
			std::cout << "Math initialized" << std::endl;

			auto radius = 1.f;
			std::cout << "Radius initialized" << std::endl;

			for (size_t i = 0; i < processData->iterationsCount; ++i)
			{
				auto x = randomizer.Get(-radius, radius);
				auto y = randomizer.Get(-radius, radius);
				std::cout << "Try hit: " << x << " " << y << std::endl;

				if (math.HitTest(x, y, radius))
				{
					std::cout << "Hit success for: " << x << " " << y << std::endl;
					InterlockedIncrement(processData->pointsInside);
					std::cout << "Increment completed: " << x << " " << y << std::endl;
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
		auto processData = InitActions();
		auto result = InvokeActions(processData);

		m_threads.clear();

		return result;
	}

	std::vector<ProcessData> CMonteCarloCalc::InitActions()
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

		std::cout << "Iterations by threads:" << std::endl;
		std::for_each(processData.begin(), processData.end(), [](auto element) {
			std::cout << element.iterationsCount << std::endl;
		});

		return processData;
	}

	float CMonteCarloCalc::InvokeActions(std::vector<ProcessData> processData)
	{
		std::cout << "Start init actions" << std::endl;

		std::for_each(processData.begin(), processData.end(), [&](auto element) {
			m_threads.push_back(CreateThread(NULL, 0, CalcPointsAction, &element, 0, 0));
		});

		std::cout << "End init actions" << std::endl;

		WaitForMultipleObjects(DWORD(m_threads.size()), m_threads.data(), true, INFINITE);

		std::cout << "End wait actions" << std::endl;

		float innerHistCount = 0;

		std::for_each(processData.begin(), processData.end(), [&](auto element) {
			innerHistCount += *element.pointsInside;
		});

		return 4.f * innerHistCount / m_iterationsCount;
	}
}
