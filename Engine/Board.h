#pragma once
#include "Graphics.h"
#include "GridLocation.h"
#include <assert.h>
class Board
{
public:
	Board(Graphics& gfx);
	~Board();

	int GetGridWidth() const;
	int GetGridHeight() const;
	void DrawCell(GridLocation& new_loc, Color c);

private:
	static constexpr int Width = 10; 
	static constexpr int Height = 10;
	static constexpr int Dimension = 20;
	Graphics& graphics;
};

