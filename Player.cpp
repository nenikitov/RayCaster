#include "Player.h"
#include <corecrt_math_defines.h>

// Constructor
Player::Player(Controller& controller, Level& level) : controller(controller), level(level)
{
	this->circle.setFillColor(this->COLOR);
	this->circle.setOrigin(this->circle.getRadius(), this->circle.getRadius());
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
	// Some values that will be necessary for calculating movement
	const double cs = cos(this->angle * M_PI / 180);
	const double sn = sin(this->angle * M_PI / 180);
	const double movSpeed = double(deltaTime) * this->MOV_SPEED / level.getTileSize() * 16;
	const double rotSpeed = double(deltaTime) * this->ROT_SPEED;
	const int fwd = this->controller.getMovementDirection().y;
	const int rwd = -this->controller.getMovementDirection().x;
	const int rot = this->controller.getLookDir();

	// Update internal location and rotation
	this->angle -= rot * rotSpeed;
	this->positionX += movSpeed * (cs * fwd + sn * rwd);
	this->positionY += movSpeed * (sn * fwd - cs * rwd);
	

	// Update shapes location and rotations
	this->circle.setPosition(this->positionX, this->positionY);
	this->line.setPosition(this->positionX, this->positionY);
	this->line.setRotation(this->angle);
}
