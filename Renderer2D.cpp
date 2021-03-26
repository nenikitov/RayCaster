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
		this->levelTiles.push_back({});
		for (unsigned int x = 0; x < level.getWidth(); x++) 
		{
			unsigned int tile = level.tileAt(x,y);

			if (tile)
			{
				sf::RectangleShape newRect = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
				newRect.setPosition(x * tileSize, y * tileSize);
				newRect.setFillColor(sf::Color(tile * 50, tile * 50, tile * 50));
				this->levelTiles[y].push_back(newRect);
			}
			else
				this->levelTiles[y].push_back(sf::RectangleShape());
		}
	}
	
}

void Renderer2D::render()
{
	window.clear();
	for (unsigned int y = 0; y < this->levelTiles.size(); y++)
	{
		for (unsigned int x = 0; x < this->levelTiles.at(y).size(); x++)
		{
			if (this->levelTiles.at(y).at(x).getSize().x)
				window.draw(this->levelTiles.at(y).at(x));
		}
	}
}