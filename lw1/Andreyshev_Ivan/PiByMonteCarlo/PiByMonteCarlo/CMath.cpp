#include "CMath.h"

namespace PiCalc
{
	bool CMath::HitTest(float x, float y, float radius)
	{
		return (x * x) + (y * y) <= (radius * radius);
	}
}
