#include "Renderer3D.h"
#include <algorithm>

Renderer3D::Renderer3D(unsigned int width, sf::RenderWindow& window, unsigned int fov, unsigned int rayCount, Level& level, Player& player)
	: window(window), lineTracer(LineTracer(level)), player(player), FOV(fov), RAY_COUNT(rayCount)
{
	const unsigned int HORIZONTAL_STEP = width / rayCount;
	const unsigned int NEW_W = HORIZONTAL_STEP * rayCount;

	window.setSize(sf::Vector2u(NEW_W, NEW_W * 0.5625));
	sf::FloatRect visibleArea(0, 0, rayCount, 1);
	window.setView(sf::View(visibleArea));
}
void Renderer3D::render()
{
	window.clear();
	
	const double HALF_FOV = this->FOV / 2;
	const double FOV_STEP = this->FOV / this->RAY_COUNT;
	Intersection intersection;
	sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(1.f, 0.f));


	for (int i = 0; i < this->RAY_COUNT; i++)
	{
		const double ANGLE = -HALF_FOV + FOV_STEP * i;
		intersection = lineTracer.findIntersection(player.getPositionX(), player.getPositionY(), player.getAngle() + ANGLE);

		if (intersection.getIntersects()) {
			const double DISTANCE = sqrt(pow(player.getPositionX() - intersection.getX(), 2) + pow(player.getPositionY() - intersection.getY(), 2));
			const double HEIGHT = 0.5 / DISTANCE;
			rectangle.setSize(sf::Vector2f(1.f, HEIGHT));
			rectangle.setPosition(i, (1 - HEIGHT) / 2);
			sf::Color color;
			switch (intersection.getTile()) 
			{
				case 1:
					color = sf::Color::Red;
					break;
				case 2:
					color = sf::Color::Cyan;
					break;
				case 3:
					color = sf::Color::Yellow;
					break;
				case 4:
					color = sf::Color::Green;
					break;
				case 5:
					color = sf::Color::Blue;
					break;
			}
			double intensity = ((intersection.getWallDirection() == WallDirection::UP || intersection.getWallDirection() == WallDirection::DOWN) ? 0.75 : 1.f) * std::fmin(1, HEIGHT);
			rectangle.setFillColor(sf::Color(color.r * intensity, color.g * intensity, color.b * intensity));
			window.draw(rectangle);
		}
	}
}