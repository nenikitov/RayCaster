#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>
class Controller
{
	public:
		// Constructor
		Controller();
		// Getters
		sf::Vector2i getMovementDirection();
		int getLookDir();
	private:
		// Player input output
		sf::Vector2i movementDirection;
		int lookDir;
		void keyEvent(sf::Keyboard::Key key, bool pressed);
		// Controls
		sf::Keyboard::Key controls[6];
		bool controlKeysPressed[6];
		void updateControls();
};

