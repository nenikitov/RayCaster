#include <iostream>

#pragma once
class Level
{
	public:
		Level(std::string path);
	private:
		unsigned int dimensionX = 0;
		unsigned int dimensionY = 0;
		unsigned int tileSize = 0;
};