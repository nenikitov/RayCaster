#include "Player.h"

// Constructor
Player::Player(Controller& controller, Level& level) : controller(controller), level(level)
{
	// Check if this can be removed
	this->controller = controller;
	this->level = level;

	this->circle.setFillColor(this->COLOR);
	this->line.setFillColor(this->COLOR);
}
// Getters
sf::CircleShape Player::getCircleShape()
{
	return this->circle;
}
sf::RectangleShape Player::getRectangle()
{
	return this->line;
}
int Player::getPositionX()
{
	return this->positionX;
}
int Player::getPositionY()
{
	return this->positionY;
}
double Player::getAngle()
{
	return this->angle;
}