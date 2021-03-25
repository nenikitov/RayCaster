#include "Player.h"

Player::Player(Controller& controller) : controller(controller)
{
	// Check if this can be removed
	this->controller = controller;

	this->circle.setFillColor(this->COLOR);
	this->line.setFillColor(this->COLOR);
}

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
