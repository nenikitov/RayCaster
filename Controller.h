#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>
class Controller
{
	public:
		// Getters
		/// <summary>
		/// Gets the movement direction vector.
		/// </summary>
		/// <returns>The movement direction vector. X is horizontal axis, Y is vertical. Can be -1 (backward or leftward), 0 (no input) or 1 (forward or rightward).</returns>
		sf::Vector2i getMovementDirection();
		/// <summary>
		/// Gets the look rotation direction
		/// </summary>
		/// <returns>The look direction. Can be -1 (left), 0 (no input) or 1 (right).</returns>
		int getLookDir();
		/// <summary>
		/// Updates the controller.
		/// </summary>
		/// <param name="key">A key of an event.</param>
		/// <param name="pressed">If this key is pressed (true) or released (false).</param>
		void keyEvent(sf::Keyboard::Key key, bool pressed);
	private:
		// Player input output
		sf::Vector2i movementDirection = sf::Vector2i(0, 0);
		int lookDir = 0;
		// Controls
		sf::Keyboard::Key controls[6] = 
		{
			sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A, // Movement WASD
			sf::Keyboard::Right, sf::Keyboard::Left // Looking - Left and Right Arrows
		};
		bool controlKeysPressed[6] = {false, false, false, false, false, false};
		// Update methods
		void updateControls();
};

