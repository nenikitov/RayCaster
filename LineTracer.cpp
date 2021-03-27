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
	

	// Test vertical walls
	Intersection verticalIntersection = Intersection(0, 0, 0, WallDirection::UP, false);
	bool foundVertical = false;
	// If facing up or down
	if (sin(-rotation * M_PI / 180) >= 0)
	{
		// Test for UP walls
		for (unsigned int i = 0; i < this->MAX_TESTS; i++)
		{
			if (foundVertical) break;

			double intersectionX = startX + (offsetY + i) / tn;
			double intersectionY = startY - offsetY - i - 0.001;

			unsigned int tile = level.tileAt(intersectionX, intersectionY);

			if (tile) {
				verticalIntersection = Intersection(intersectionX, intersectionY, tile, WallDirection::UP, true);
				foundVertical = true;
			}
		}
	}
	else
	{
		// Test for DOWN walls
		for (unsigned int i = 0; i < this->MAX_TESTS; i++)
		{
			if (foundVertical) break;

			double intersectionX = startX + (i + 1 - offsetY) / -tn;
			double intersectionY = startY + i + 1 - offsetY + 0.001;

			unsigned int tile = level.tileAt(intersectionX, intersectionY);

			if (tile) {
				verticalIntersection = Intersection(intersectionX, intersectionY, tile, WallDirection::DOWN, true);
				foundVertical = true;
			}
		}
	}

	// Test for horizontal walls
	Intersection horizontalIntersection = Intersection(0, 0, 0, WallDirection::RIGHT, false);
	bool foundHorizontal = false;
	// If facing right or left
	if (cos(-rotation * M_PI / 180) >= 0)
	{
		// Test for RIGHT walls
		for (unsigned int i = 0; i < this->MAX_TESTS; i++)
		{
			if (foundHorizontal) break;

			double intersectionX = startX + i + 1 - offsetX + 0.001;
			double intersectionY = startY - (i + 1 - offsetX) * tn;

			unsigned int tile = level.tileAt(intersectionX, intersectionY);

			if (tile) {
				horizontalIntersection = Intersection(intersectionX, intersectionY, tile, WallDirection::RIGHT, true);
				foundHorizontal = true;
			}
		}
	}
	else 
	{
		// Test for LEFT walls
		for (unsigned int i = 0; i < this->MAX_TESTS; i++)
		{
			if (foundHorizontal) break;

			double intersectionX = startX - offsetX - i - 0.001;
			double intersectionY = startY - (offsetX + i) * -tn;

			unsigned int tile = level.tileAt(intersectionX, intersectionY);

			if (tile) {
				horizontalIntersection = Intersection(intersectionX, intersectionY, tile, WallDirection::LEFT, true);
				foundHorizontal = true;
			}
		}
	}

	// Return empty intersection if none exists
	if (!foundHorizontal && !foundVertical)
		return Intersection(0, 0, 0, WallDirection::UP, false);
	// Return the one that exists
	else if (!foundHorizontal && foundVertical)
		return verticalIntersection;
	else if (foundHorizontal && !foundVertical)
		return horizontalIntersection;
	// Or return the closest one if both exists
	else
	{
		double distHor =
			abs(horizontalIntersection.getX() - startX) * abs(horizontalIntersection.getX() - startX)
			+ abs(horizontalIntersection.getY() - startY) * abs(horizontalIntersection.getY() - startY);

		double distVert =
			abs(verticalIntersection.getX() - startX) * abs(verticalIntersection.getX() - startX)
			+ abs(verticalIntersection.getY() - startY) * abs(verticalIntersection.getY() - startY);

		if (distVert < distHor)
			return verticalIntersection;
		else
			return horizontalIntersection;
	}
}
Intersection LineTracer::lineTrace(double startX, double startY, double tn, WallDirection direction)
{
	const double offsetX = fmod(startX, 1);
	const double offsetY = fmod(startY, 1);

	switch (direction)
	{
		case WallDirection::UP:
			// Check for walls in the direction
			for (unsigned int i = 0; i < this->MAX_TESTS; i++)
			{
				double intersectionX = startX + (offsetY + i) / tn;
				double intersectionY = startY - offsetY - i - 0.001;

				unsigned int tile = level.tileAt(intersectionX, intersectionY);

				if (tile)
					return Intersection(intersectionX, intersectionY, tile, WallDirection::UP, true);
			}
			// Nothing found, return empty intersection
			return Intersection(0, 0, 0, WallDirection::UP, false);
			break;
		case WallDirection::DOWN:
			// Check for walls in the direction
			for (unsigned int i = 0; i < this->MAX_TESTS; i++)
			{
				double intersectionX = startX + (i + 1 - offsetY) / -tn;
				double intersectionY = startY + i + 1 - offsetY + 0.001;

				unsigned int tile = level.tileAt(intersectionX, intersectionY);

				if (tile)
					return Intersection(intersectionX, intersectionY, tile, WallDirection::DOWN, true);
			}
			// Nothing found, return empty intersection
			return Intersection(0, 0, 0, WallDirection::DOWN, false);
			break;
		case WallDirection::RIGHT:
			// Check for walls in the direction
			for (unsigned int i = 0; i < this->MAX_TESTS; i++)
			{
				double intersectionX = startX + i + 1 - offsetX + 0.001;
				double intersectionY = startY - (i + 1 - offsetX) * tn;

				unsigned int tile = level.tileAt(intersectionX, intersectionY);

				if (tile)
					return Intersection(intersectionX, intersectionY, tile, WallDirection::RIGHT, true);

			}
			// Nothing found, return empty intersection
			return Intersection(0, 0, 0, WallDirection::RIGHT, false);
			break;
		case WallDirection::LEFT:
			// Check for walls in the direction
			for (unsigned int i = 0; i < this->MAX_TESTS; i++)
			{
				double intersectionX = startX + i + 1 - offsetX + 0.001;
				double intersectionY = startY - (i + 1 - offsetX) * tn;

				unsigned int tile = level.tileAt(intersectionX, intersectionY);

				if (tile)
					return Intersection(intersectionX, intersectionY, tile, WallDirection::RIGHT, true);
			}
			// Nothing found, return empty intersection
			return Intersection(0, 0, 0, WallDirection::LEFT, false);
			break;
	}
}
