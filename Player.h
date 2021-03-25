#pragma once
#include "Controller.h"
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include "Level.h"

class Player
{
	public:
		// Constructor
		/// <summary>
		/// Initialize the player.
		/// </summary>
		/// <param name="controller">The controller that will control the player.</param>
		/// <param name="level">The level that the player is on.</param>
		/// <returns>Initialized player.</returns>
		Player(Controller& controller, Level& level);
		// Getters
		/// <summary>
		/// Gets the circle shape that represents the body of the player.
		/// </summary>
		/// <returns>The body circle.</returns>
		sf::CircleShape getCircleShape();
		/// <summary>
		/// Gets the rectangle shape that represents the direction arrow of the player.
		/// </summary>
		/// <returns>The direction rectangle.</returns>
		sf::RectangleShape getRectangle();
		/// <summary>
		/// Gets the position of the player along X axis.
		/// </summary>
		/// <returns>X position.</returns>
		int getPositionX();
		/// <summary>
		/// Gets the position of the player along Y axis.
		/// </summary>
		/// <returns>Y position.</returns>
		int getPositionY();
		/// <summary>
		/// Gets the rotation of the player (in degrees).
		/// </summary>
		/// <returns>Rotation.</returns>
		double getAngle();
		/// <summary>
		/// Updates the player from the controls
		/// </summary>
		void updatePlayerLocation();
	private:
		Controller& controller;
		Level& level;
		sf::CircleShape circle = sf::CircleShape(10.f);
		sf::RectangleShape line = sf::RectangleShape(sf::Vector2f(10.f, 2.f));
		const sf::Color COLOR = sf::Color::Cyan;
		int positionX = 0;
		int positionY = 0;
		double angle = 0;
};