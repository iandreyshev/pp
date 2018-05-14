#pragma once
#include <iostream>
#include "PiCalcResult.h"

namespace PiCalc
{
	class CMonteCarloCalc
	{
	public:
		CMonteCarloCalc(int iterationsCount, int threadsCount);

		PiCalcResult Get();

	private:
		int m_iterationsCount;
		int m_threadsCount;

	};
}
