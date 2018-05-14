#pragma once
#include <memory>

namespace PiCalc
{
	struct ProcessData
	{
		ProcessData(long iterationsCount)
		{
			this->iterationsCount = iterationsCount;
		}

		size_t iterationsCount;
		size_t pointsInside = 0;
	};
}
