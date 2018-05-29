#pragma once

namespace PiCalc
{
	class CRandomizer
	{
	public:
		CRandomizer();

		float Get(float min, float max);

	private:
		std::mt19937 m_randomEngine;

	};
}
