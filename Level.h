#include <iostream>
#include <vector>

#pragma once
class Level
{
	public:
		/// <summary>
		/// Initialize the level.
		/// </summary>
		/// <param name="path">The path to the text file that contains level data.</param>
		/// <returns>The level.</returns>
		Level(std::string path);
		/// <summary>
		/// Gets the tile data in the coordinates.
		/// </summary>
		/// <param name="x">X coordinate.</param>
		/// <param name="y">Y coordinate.</param>
		/// <returns>The integer that represents the tile that is at these coordinates.</returns>
		unsigned int tileAt(unsigned int x, unsigned int y);
		/// <summary>
		/// Get the tile size of the level.
		/// </summary>
		/// <returns>The tile size.</returns>
		unsigned int getTileSize();
		/// <summary>
		/// Gets the width of the level.
		/// </summary>
		/// <returns>The width.</returns>
		unsigned int getWidth();
		/// <summary>
		/// Gets the height of the level.
		/// </summary>
		/// <returns>The height of a level.</returns>
		unsigned int getHeight();
	private:
		unsigned int dimensionX = 0;
		unsigned int dimensionY = 0;
		unsigned int tileSize = 0;
		std::vector<std::vector<unsigned  int>> tileData = { {} };
};