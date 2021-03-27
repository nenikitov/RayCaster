#include "Renderer3D.h"

Renderer3D::Renderer3D(unsigned int width, sf::RenderWindow& window, unsigned int fov, unsigned int rayCount, Level& level, Player& player)
	: window(window), lineTracer(LineTracer(level)), player(player), FOV(fov), RAY_COUNT(rayCount)
{
	const unsigned int HORIZONTAL_STEP = width / rayCount;
	const unsigned int NEW_W = HORIZONTAL_STEP * rayCount;

	window.setSize(sf::Vector2u(NEW_W, NEW_W * 0.5625));
	sf::FloatRect visibleArea(0, 0, rayCount, 1);
	window.setView(sf::View(visibleArea));
}