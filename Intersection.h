#pragma once
class Intersection
{
	public:
		Intersection(double x, double y, unsigned int tile);
		double getX();
		double getY();
		unsigned int getTile();
	private:
		double x;
		double y;
		unsigned int tile;
};