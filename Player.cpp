#include "Player.h"

// Constructor
Player::Player(Controller& controller, Level& level) : controller(controller), level(level)
{
	// Check if this can be removed
	this->controller = controller;
	this->level = level;

	this->circle.setFillColor(this->COLOR);
	this->line.setFillColor(this->COLOR);
	this->line.setOrigin(0, this->line.getSize().y / 2);
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
	// Update internal location and rotation
	this->positionX += this->controller.getMovementDirection().x * double(deltaTime) * this->MOV_SPEED;
	this->positionY -= this->controller.getMovementDirection().y * double(deltaTime) * this->MOV_SPEED;
	this->angle -= this->controller.getLookDir() * double(deltaTime) * this->ROT_SPEED;

	// Update shapes location and rotations
	this->circle.setPosition(this->positionX, this->positionY);
	this->line.setPosition(this->positionX + this->circle.getRadius(), this->positionY + this->circle.getRadius());
	this->line.setRotation(this->angle);
}
