#pragma once
#include "WallDirection.cpp"
class Intersection
{
	public:
		Intersection(double x, double y, unsigned int tile, WallDirection direction, bool intersects);
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