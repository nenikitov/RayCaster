#pragma once
class Intersection
{
	public:
		Intersection(double x, double y, unsigned int tile, bool intersects);
		double getX();
		double getY();
		unsigned int getTile();
		bool getIntersects();
	private:
		double x;
		double y;
		unsigned int tile;
		bool intersects;
};