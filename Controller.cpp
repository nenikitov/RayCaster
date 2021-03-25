#include "Controller.h"

// Getters
sf::Vector2i Controller::getMovementDirection()
{
    return this->movementDirection;
}
int Controller::getLookDir()
{
    return this->lookDir;
}

// Update methods
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
