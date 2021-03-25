#include "Intersection.h"

Intersection::Intersection(double x, double y, unsigned int tile, bool intersects)
{
    this->x = x;
    this->y = y;
    this->tile = tile;
    this->intersects = intersects;
}
double Intersection::getX()
{
    return x;
}
double Intersection::getY()
{
    return y;
}
unsigned int Intersection::getTile()
{
    return tile;
}
bool Intersection::getIntersects() {
    return intersects;
}