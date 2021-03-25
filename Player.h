#pragma once
#include "Controller.h"
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

class Player
{
	public:
		Player(Controller& controller);
		sf::CircleShape getCircleShape();
		sf::RectangleShape getRectangle();
		int getPositionX();
		int getPositionY();
		double getAngle();
		void updatePlayerLocation();
	private:
		Controller& controller;
		sf::CircleShape circle = sf::CircleShape(10.f);
		sf::RectangleShape line = sf::RectangleShape(sf::Vector2f(10.f, 2.f));
		const sf::Color COLOR = sf::Color::Cyan;
		int positionX = 0;
		int positionY = 0;
		double angle = 0;
};