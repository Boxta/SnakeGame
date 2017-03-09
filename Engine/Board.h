#pragma once
#include "Graphics.h"
#include "GridLocation.h"
#include <assert.h>
class Board
{
private:

	static constexpr int Width = 40;
	static constexpr int Height = 40;
	static constexpr int CellPadding = 2;

public:
	Board(Graphics& gfx);
	~Board();

	int GetGridWidth() const;
	int GetGridHeight() const;
	void DrawCell(GridLocation& new_loc, Color c);
	bool IsOffBoard(GridLocation& newloc);
	static constexpr int Dimension = 10;
	static constexpr int Off_X_Position = Graphics::ScreenWidth - (Dimension * Width) - (Width * CellPadding) - 50;
	static constexpr int Off_Y_Position = Graphics::ScreenHeight - (Dimension * Height) - (Height * CellPadding) - 50;

	

	Graphics& graphics;
};

