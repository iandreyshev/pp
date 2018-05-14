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
		const int MIN_THREADS_COUNT = 1;

		DWORD WINAPI CalcPointsAction(LPVOID param)
		{
			ProcessData* processData = reinterpret_cast<ProcessData*>(param);
			CRandomizer randomizer = CRandomizer();
			CMath math = CMath();
			auto radius = 1.f;

			for (size_t i = 0; i < 100; ++i)
			{
				auto x = randomizer.Get(-radius, radius);
				auto y = randomizer.Get(-radius, radius);

				if (math.HitTest(x, y, radius))
				{
					InterlockedIncrement(&processData->pointsInside);
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
		float result;

		if (m_threadsCount == 1)
		{
			result = InvokeActions(processData);
		}
		else
		{
			result = InvokeActionsAsync(processData);
		}

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

		return processData;
	}

	float CMonteCarloCalc::InvokeActionsAsync(std::vector<ProcessData> &processData)
	{
		std::for_each(processData.begin(), processData.end(), [&](ProcessData& element) {
			auto thread = CreateThread(NULL, 0, CalcPointsAction, &element, 0, 0);
			m_threads.push_back(thread);
		});

		WaitForMultipleObjects(DWORD(m_threads.size()), m_threads.data(), true, INFINITE);

		float innerHistCount = 0;

		std::for_each(processData.begin(), processData.end(), [&](auto element) {
			innerHistCount += element.pointsInside;
		});

		return 4.f * innerHistCount / m_iterationsCount;
	}

	float CMonteCarloCalc::InvokeActions(std::vector<ProcessData> &processData)
	{
		CalcPointsAction(&processData[0]);

		float innerHistCount = 0;

		std::for_each(processData.begin(), processData.end(), [&](auto element) {
			innerHistCount += element.pointsInside;
		});

		return 4.f * innerHistCount / m_iterationsCount;
	}
}
