#include <iostream>
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Level.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "RayCaster", sf::Style::Close);
    sf::Clock deltaClock;
    Controller playerController;
    Level level = Level("./Levels/LevelTest.txt");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = deltaClock.restart();


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}