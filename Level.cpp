#include "Level.h"
#include <fstream>
#include <string>

Level::Level(std::string path)
{
	// Read level data file
	char currentChar;
	std::string word = "";
	int wordCount = 0;
	
	std::fstream fin(path, std::fstream::in);
	while (fin >> std::noskipws >> currentChar)
	{
		if (currentChar == ' ')
		{
			int value = std::stoi(word);

			switch (wordCount)
			{
				// Dimension X declaration
				case 0:
					if (value > 0)
					{
						std::cout << "Dimensions X initialized to " << value << std::endl;
						this->dimensionX = abs(value);
					}
					else
						throw std::runtime_error("Dimension X is not valid");
					break;
				// Dimension Y declaration
				case 1:
					if (value > 0)
					{
						std::cout << "Dimensions Y initialized to " << value << std::endl;
						this->dimensionY = abs(value);
					}
					else
						throw std::runtime_error("Dimension Y is not valid");
					break;
				// Tile size declaration
				case 2:
					if (value > 0)
					{
						std::cout << "Tile size initialized to " << value << std::endl;
						this->tileSize = value;
					}
					else
						throw std::runtime_error("Tile size is not valid");
					break;
				default:
					
					break;
			}

			wordCount++;
			word = "";
		}
		else
			word += currentChar;
	}
}
