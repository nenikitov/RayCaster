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
			if (word.length() != 0)
			{
				int value;
				switch (wordCount)
				{
					// Dimension X declaration
					case 0:
						value = std::stoi(word);
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
						value = std::stoi(word);
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
						value = std::stoi(word);
						if (value > 0)
						{
							std::cout << "Tile size initialized to " << value << std::endl;
							this->tileSize = value;
						}
						else
							throw std::runtime_error("Tile size is not valid");

						break;

					// Level field declaration
					default:
						if (word == "-") // "Line break" for the level data for auto completition
						{
							if (levelX < this->dimensionX) // Autocomplete level row
							{
								for ( ; levelX < this->dimensionX; levelX++)
									this->tileData[levelY].push_back(0);
							}
							else if (levelX > this->dimensionX) // Invalid data
								throw std::runtime_error("Width of the level is not valid");
							
							this->tileData.push_back({});
							levelY++;
							levelX = 0;
							if (levelY >= this->dimensionY)
								throw std::runtime_error("Height of the level is not valid");
						}
						else
						{
							value = std::stoi(word);

							this->tileData[levelY].push_back(value);
							levelX++;
							break;
						}
				}

				word = "";
				wordCount++;
			}
		}
		else
			word += currentChar;
	}

	levelY++;
	if (levelY < this->dimensionY)
	{
		for (; levelY < this->dimensionY; levelY++) {
			this->tileData.push_back({});
			for (unsigned int i = 0; i < this->dimensionX; i++)
				this->tileData[levelY].push_back(0);
		}
	}

	for (unsigned int i = 0; i < this->tileData.size(); ++i)
	{
		for (unsigned int j = 0; j < this->tileData[i].size(); ++j)
			std::cout << this->tileData[i][j];
		std::cout << std::endl;
	}
}