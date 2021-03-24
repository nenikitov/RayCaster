#include "Level.h"
#include <fstream>
#include <string>

Level::Level(std::string path)
{
	char currentChar;
	std::string word = "";
	int wordCount = 0;
	int levelX = 0;
	int levelY = 0;
	// Read level data file
	std::fstream fileData(path, std::fstream::in);
	while (fileData >> std::noskipws >> currentChar)
	{
		if (currentChar == ' ' || currentChar == '\n')
		{
			// Ignores "words" in between spaces, so the level data can be formated better
			if (word.length() != 0)
			{
				int value;
				switch (wordCount)
				{
					#pragma region Dimension X declaration
					case 0:
						value = std::stoi(word);
						// Check the value
						if (value > 0)
						{
							std::cout << "Dimensions X initialized to " << value << std::endl;
							this->dimensionX = abs(value);
						}
						else
							throw std::runtime_error("Dimension X is not valid");

						break;
					#pragma endregion
					#pragma region Dimension Y declaration
					case 1:
						value = std::stoi(word);
						// Check the value
						if (value > 0)
						{
							std::cout << "Dimensions Y initialized to " << value << std::endl;
							this->dimensionY = abs(value);
						}
						else
							throw std::runtime_error("Dimension Y is not valid");

						break;
					#pragma endregion
					#pragma region  Tile size declaration
					case 2:
						value = std::stoi(word);
						// Check the value
						if (value > 0)
						{
							std::cout << "Tile size initialized to " << value << std::endl;
							this->tileSize = value;
						}
						else
							throw std::runtime_error("Tile size is not valid");

						break;
					#pragma endregion
					#pragma region Level field declaration
					default:
						if (word == "-") 
						{
							// "Line break" for the level data for auto completition

							// Autocomplete level row if it is incomplete
							if (levelX < this->dimensionX)
							{
								for ( ; levelX < this->dimensionX; levelX++)
									this->tileData[levelY].push_back(0);
							}
							// Check for invalid data
							else if (levelX > this->dimensionX)
								throw std::runtime_error("Width of the level is not valid");
							
							// Add a new line in the level tile data, go to it
							this->tileData.push_back({});
							levelY++;
							levelX = 0;
							// Check for invalid data
							if (levelY >= this->dimensionY)
								throw std::runtime_error("Height of the level is not valid");
						}
						else
						{
							// Add tile data to the vector

							value = std::stoi(word);
							// Check the value
							if (value >= 0)
								this->tileData[levelY].push_back(value);
							else
								throw std::runtime_error("Tile data is not valid");

							// Go to next tile
							levelX++;
							break;
						}
				}
				#pragma endregion
				// End of the word, clear it
				word = "";
				wordCount++;
			}
		}
		// Still in a word, add the character to it
		else
			word += currentChar;
	}

	// Autocomplete level colums if level is incomplete
	levelY++;
	if (levelY < this->dimensionY)
	{
		for (; levelY < this->dimensionY; levelY++) {
			this->tileData.push_back({});
			for (unsigned int i = 0; i < this->dimensionX; i++)
				this->tileData[levelY].push_back(0);
		}
	}
}

unsigned int Level::tileAt(unsigned int x, unsigned int y)
{
	if (x < 0 || x >= dimensionX || y < 0 || y >= dimensionY)
		return 0;
	else
		return this->tileData[x][y];
}

unsigned int Level::getTileSize()
{
	return this->tileSize;
}

unsigned int Level::getWidth()
{
	return this->dimensionX;
}

unsigned int Level::getHeight()
{
	return this->dimensionY;
}
