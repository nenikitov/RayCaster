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
		sf::RectangleShape getRectangleShape();
		/// <summary>
		/// Gets the position of the player along X axis.
		/// </summary>
		/// <returns>X position.</returns>
		double getPositionX();
		/// <summary>
		/// Gets the position of the player along Y axis.
		/// </summary>
		/// <returns>Y position.</returns>
		double getPositionY();
		/// <summary>
		/// Gets the rotation of the player (in degrees).
		/// </summary>
		/// <returns>Rotation.</returns>
		double getAngle();
		// Update methods
		/// <summary>
		/// Updates the player from the controls.
		/// </summary>
		/// <param name="deltaTime">The time between frames (in seconds) so the physics are untied from the framerate.</param>
		void updatePlayerLocation(float deltaTime);
	private:
		Controller& controller;
		Level& level;
		sf::CircleShape circle = sf::CircleShape(10.f);
		sf::RectangleShape line = sf::RectangleShape(sf::Vector2f(20.f, 2.f));
		const sf::Color COLOR = sf::Color::Cyan;
		const double SPEED = 50;
		double positionX = 0;
		double positionY = 0;
		double angle = 0;
};