#include <iostream>
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Level.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window2d(sf::VideoMode(512, 512), "RayCaster - 2D", sf::Style::Close);
    sf::RenderWindow window3d(sf::VideoMode(1280, 720), "RayCaster - 3D", sf::Style::Close);
    sf::Clock deltaClock;


    Controller playerController;
    Level level = Level("./Levels/LevelTest.txt");
    Player player = Player(playerController, level);

    while (window2d.isOpen())
    {
        // Check if window 3d was closed
        sf::Event event3d;
        if (window3d.pollEvent(event3d))
        {
            if (event3d.type == sf::Event::Closed)
            {
                window2d.close();
                window3d.close();
            }
        }

        // Check if window 2d was closed
        sf::Event event2d;
        while (window2d.pollEvent(event2d))
        {
            if (event2d.type == sf::Event::Closed)
            {
                window2d.close();
                window3d.close();
            }
        }

        // Update window 2d
        sf::Time deltaTime = deltaClock.restart();
        window2d.clear();
        window2d.draw(player.getCircleShape());
        window2d.draw(player.getRectangleShape());
        window2d.display();
    }

    return 0;
}