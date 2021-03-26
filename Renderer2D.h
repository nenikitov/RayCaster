#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "Level.h"
class Renderer2D
{
	public:
		Renderer2D(sf::RenderWindow window, Level level);
		void update();
	private:
		sf::RenderWindow& window;
		Level& level;
};
