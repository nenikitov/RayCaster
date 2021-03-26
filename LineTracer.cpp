#include "LineTracer.h"
#include <corecrt_math_defines.h>

LineTracer::LineTracer(Level& level) : level(level)
{
}

Intersection LineTracer::findIntersection(double startX, double startY, double rotation)
{
	const unsigned int tileSize = this->level.getTileSize();
	const double tn = tan(-rotation * M_PI / 180);
	const double offsetX = fmod(startX, 1);
	const double offsetY = fmod(startY, 1);

	// Test for UP walls
	for (unsigned int i = 0; i < this->MAX_TESTS; i++)
	{
		double intersectionX = startX + (offsetY + i) / tn;
		double intersectionY = startY - offsetY - i - 0.001;

		unsigned int tile = level.tileAt(intersectionX, intersectionY);

		if (tile)
			return Intersection(intersectionX, intersectionY, i, true);
	}

	return Intersection(0, 0, 0, false);
}
