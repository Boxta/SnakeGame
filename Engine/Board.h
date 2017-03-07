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
	bool IsOnBoard(GridLocation& newloc);
private:
	static constexpr int Dimension = 10;
	static constexpr int Width = 40; 
	static constexpr int Height = 40;
	static constexpr int Off_X_Position = 100;
	static constexpr int Off_Y_Position = 100;
	static constexpr int CellPadding = 2;
	Graphics& graphics;
};

