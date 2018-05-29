#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>

namespace PiCalc
{
	class CMonteCarloCalc
	{
	public:
		CMonteCarloCalc(int iterationsCount);

		float Get();

	private:
		int m_iterationsCount;

	};
}

