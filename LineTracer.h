#pragma once
#include "Player.h"
#include "Intersection.h"

class LineTracer
{
	public:
		LineTracer(Level& level);
		Intersection findIntersection(double startX, double startY, double rotation);
	private:
		Level& level;
		const unsigned int MAX_TESTS = 18;
		Intersection lineTrace(double startX, double startY, double tn, WallDirection direction);
};