#pragma once
class LevelGrid
{
	public:
		LevelGrid(unsigned int dimensionX, unsigned int dimensionY, unsigned char layout[]);
		unsigned char tileAt(unsigned int x, unsigned int y);
	private:
		unsigned int dimensionX;
		unsigned int dimensionY;
		unsigned char layout[];
};