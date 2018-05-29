#include "CMath.h"

namespace PiCalc
{
	bool CMath::HitTest(float x, float y, float radius) const
	{
		return (x * x) + (y * y) <= (radius * radius);
	}
}
