#include "Intersection.h"


Intersection::Intersection(double x, double y, unsigned int tile, WallDirection direction, bool intersects)
{
    this->x = x;
    this->y = y;
    this->tile = tile;
    this->direction = direction;
    this->intersects = intersects;
}

double Intersection::getX()
{
    return this->x;
}
double Intersection::getY()
{
    return this->y;
}
unsigned int Intersection::getTile()
{
    return this->tile;
}
bool Intersection::getIntersects() {
    return this->intersects;
}

WallDirection Intersection::getWallDirection()
{
    return this->direction;
}
