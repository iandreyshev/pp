#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>

namespace PiCalc
{
	class CMonteCarloCalc
	{
	public:
		CMonteCarloCalc(int iterationsCount, int threadsCount);

		float Get();

	private:
		void InitActions();
		void InvokeActions();

		int m_iterationsCount;
		int m_threadsCount;

		std::vector<HANDLE> m_threads;

	};
}

