#include "LineTracer.h"

LineTracer::LineTracer(Level& level) : level(level)
{
}

Intersection LineTracer::findIntersection(double startX, double startY, double rotation)
{
	const unsigned int tileSize = this->level.getTileSize();


	return Intersection(0, 0, 0, false);
}
