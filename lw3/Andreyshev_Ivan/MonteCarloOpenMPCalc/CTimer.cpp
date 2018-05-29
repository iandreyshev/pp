#include "CTimer.h"

namespace PiCalc
{
	void CTimer::Start()
	{
		m_startTime = std::chrono::steady_clock::now();
	}

	Duration CTimer::Stop()
	{
		auto nowTime = std::chrono::steady_clock::now();
		auto timePassed = nowTime - m_startTime;

		return std::chrono::duration_cast<Duration>(timePassed);
	}
}
