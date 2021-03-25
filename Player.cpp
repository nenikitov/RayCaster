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
sf::RectangleShape Player::getRectangleShape()
{
	return this->line;
}
double Player::getPositionX()
{
	return this->positionX;
}
double Player::getPositionY()
{
	return this->positionY;
}
double Player::getAngle()
{
	return this->angle;
}
// Update methods
void Player::updatePlayerLocation(float deltaTime)
{
	this->positionX += this->controller.getMovementDirection().x * double(deltaTime) * this->SPEED;
	this->positionY -= this->controller.getMovementDirection().y * double(deltaTime) * this->SPEED;

	this->circle.setPosition(this->positionX, this->positionY);
}
