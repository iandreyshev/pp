#pragma once

namespace PiCalc
{
	struct ProcessData
	{
		ProcessData(long iterationsCount)
			: iterationsCount(iterationsCount)
		{
		}

		size_t iterationsCount;
		size_t* pointsInside = 0;
	};
}
