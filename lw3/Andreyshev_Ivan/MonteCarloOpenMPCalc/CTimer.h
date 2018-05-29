#pragma once
#include <chrono>

namespace PiCalc
{
	using Duration = std::chrono::duration<float>;

	class  CTimer
	{
	public:
		void Start();
		Duration Stop();

	private:
		std::chrono::time_point<std::chrono::steady_clock> m_startTime;

	};
}
