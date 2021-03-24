#include <iostream>
#include <vector>

#pragma once
class Level
{
	public:
		Level(std::string path);
	private:
		unsigned int dimensionX = 0;
		unsigned int dimensionY = 0;
		unsigned int tileSize = 0;
		std::vector<std::vector<unsigned  int>> tileData = { {} };
};