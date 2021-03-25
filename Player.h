#pragma once
#include "Controller.h"

class Player
{
	public:
		Player(Controller controller);
		int getPositionX();
		int getPositionY();
		double getAngle();
		void updatePlayerLocation();
	private:
		Controller controller;
		int positionX = 0;
		int positionY = 0;
		double angle = 0;
};