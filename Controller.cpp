
#include "Controller.h"

Controller::Controller()
{
    // Initialize controls
    this->controls[0] = sf::Keyboard::W;
    this->controls[1] = sf::Keyboard::S;
    this->controls[2] = sf::Keyboard::D;
    this->controls[3] = sf::Keyboard::A;
    this->controls[4] = sf::Keyboard::Right;
    this->controls[5] = sf::Keyboard::Left;
    // Initialize control key pressed
    for (int i = 0; i < (sizeof(this->controlKeysPressed) / sizeof(this->controlKeysPressed[0])); i++)
        controlKeysPressed[i] = false;
    // Initialize movement direction and look input
    this->movementDirection = sf::Vector2i(0, 0);
    this->lookDir = 0;
}

sf::Vector2i Controller::getMovementDirection()
{
    return this->movementDirection;
}

int Controller::getLookDir()
{
    return this->lookDir;
}

void Controller::keyEvent(sf::Keyboard::Key key, bool pressed)
{
    // For each controls key
    for (int i = 0; i < (sizeof(this->controls)/sizeof(this->controls[0])); i++)
    {
        if (key == this->controls[i]) {
            this->controlKeysPressed[i] = pressed;
            this->updateControls();
        }
    }
}

void Controller::updateControls()
{
    this->movementDirection.x = this->controlKeysPressed[2] - this->controlKeysPressed[3];
    this->movementDirection.y = this->controlKeysPressed[0] - this->controlKeysPressed[1];
    this->lookDir = this->controlKeysPressed[5] - this->controlKeysPressed[4];
}
