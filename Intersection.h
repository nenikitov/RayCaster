#pragma once
#include "WallDirection.cpp"
class Intersection
{
	public:
		Intersection(double x = 0, double y = 0, unsigned int tile = 0, WallDirection direction = WallDirection::UP, bool intersects = false);
		double getX();
		double getY();
		unsigned int getTile();
		bool getIntersects();
		WallDirection getWallDirection();
	private:
		double x;
		double y;
		unsigned int tile;
		bool intersects;
		WallDirection direction;
};