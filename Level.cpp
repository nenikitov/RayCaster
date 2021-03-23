#include "Level.h"
#include <fstream>

Level::Level(std::string path)
{
	// Read level data file
	char ch;
	std::fstream fin(path, std::fstream::in);
		while (fin >> std::noskipws >> ch)
			std::cout << ch;
}
