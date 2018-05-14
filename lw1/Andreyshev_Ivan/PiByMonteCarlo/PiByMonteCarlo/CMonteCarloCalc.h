#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>

#include "ProcessData.h"

namespace PiCalc
{
	class CMonteCarloCalc
	{
	public:
		CMonteCarloCalc(int iterationsCount, int threadsCount);

		float Get();

	private:
		std::vector<ProcessData> InitActions();

		float InvokeActions(std::vector<ProcessData> &processData);
		float InvokeActionsAsync(std::vector<ProcessData> &processData);

		int m_iterationsCount;
		int m_threadsCount;

		std::vector<HANDLE> m_threads;

	};
}

