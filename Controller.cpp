
#include "Controller.h"

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
        if (key == this->controls[i])
            this->controlKeysPressed[i] = pressed;
    }
}

void Controller::updateControls()
{
}
