#pragma once

namespace PiCalc
{
	struct ProcessData
	{
		ProcessData(long iterationsCount)
		{
			this->iterationsCount = iterationsCount;
			size_t countInside = 0;
			pointsInside = &countInside;
		}

		size_t iterationsCount;
		size_t* pointsInside;
	};
}
