#pragma once
#include "Level.h"
#include "Player.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include "LineTracer.h"

class Renderer3D
{
	public:
		Renderer3D(unsigned int width, sf::RenderWindow& window, unsigned int fov, unsigned int rayCount, Level& level, Player& player);
		void render();
	private:
		sf::RenderWindow& window;
		Player& player;
		LineTracer lineTracer;
		const unsigned int FOV;
		const unsigned int RAY_COUNT;
};