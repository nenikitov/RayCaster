#include "Renderer2D.h"

Renderer2D::Renderer2D(sf::RenderWindow& window, Level& level) : window(window)
{
	const unsigned tileSize = this->TARGET_WINDOW_SIZE / level.getHeight();
	const unsigned int newW = tileSize * level.getWidth();
	const unsigned int newH = tileSize * level.getHeight();
	window.setSize(sf::Vector2u(newW, newH));
	sf::FloatRect visibleArea(0, 0, newW, newH);
	window.setView(sf::View(visibleArea));

	
	for (unsigned int y = 0; y < level.getHeight(); y++) 
	{
		std::cout << "Should push into 2d array" << std::endl;
		//this->levelTiles.push_back({});
		for (unsigned int x = 0; x < level.getWidth(); x++) 
		{
			unsigned int tile = level.tileAt(x,y);
			
			//if (tile)
			//{
				//this->levelTiles[y].push_back(sf::RectangleShape(sf::Vector2f(0, 0)));
			//}
		}
	}
	
}

void Renderer2D::update()
{
}