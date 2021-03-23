#pragma once
class Controller
{
	public:
		sf::Vector2i getMovementDirection();
		int getLookDir();
	private:
		// Player input output
		sf::Vector2i movementDirection;
		int lookDir;
		void keyEvent(sf::Keyboard::Key, bool pressed);
		// Controls
		sf::Keyboard::Key controls[6] =
		{
			sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D,
			sf::Keyboard::Left, sf::Keyboard::Right
		};
		bool controlKeysPressed[6] = { false, false, false, false, false, false };
		void updateControls();
};

