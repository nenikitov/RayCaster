#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "Level.h"
#include <SFML\Graphics\RectangleShape.hpp>

class Renderer2D
{
	public:
		Renderer2D(sf::RenderWindow& window, Level& level);
		void render();
	private:
		sf::RenderWindow& window;
		std::vector<std::vector<sf::RectangleShape>> levelTiles = { {} };
		const unsigned int TARGET_WINDOW_SIZE = 512;
};