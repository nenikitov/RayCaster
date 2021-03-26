#include "LineTracer.h"
#include <corecrt_math_defines.h>

LineTracer::LineTracer(Level& level) : level(level)
{
}

Intersection LineTracer::findIntersection(double startX, double startY, double rotation)
{
	const unsigned int tileSize = this->level.getTileSize();
	const double tn = tan(-rotation * M_PI / 180);
	const double offsetX = fmod(startX, tileSize);
	const double offsetY = fmod(startY, tileSize);

	// Test for UP walls
	for (unsigned int i = 0; i < this->MAX_TESTS; i++)
	{
		double intersectionX = startX + (offsetY + i * double(tileSize)) / tn;
		double intersectionY = startY - offsetY - i * double(tileSize);

		unsigned int tileX = fmod(intersectionX, tileSize);
		unsigned int tileY = fmod(intersectionY, tileSize);
		unsigned int tile = level.tileAt(tileX, tileY);

		if (tile)
			return Intersection(intersectionX, intersectionY, i, true);
	}

	return Intersection(0, 0, 0, false);
}
