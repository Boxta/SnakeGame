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
	bool IsOffBoard(GridLocation& newloc);
private:
	static constexpr int Dimension = 10;
	static constexpr int Width = 40; 
	static constexpr int Height = 40;
	static constexpr int CellPadding = 2;
	static constexpr int Off_X_Position = Graphics::ScreenWidth - (Dimension * Width) - (Width * CellPadding) - 1;
	static constexpr int Off_Y_Position = Graphics::ScreenHeight - (Dimension * Height) - (Height * CellPadding) - 1;

	Graphics& graphics;
};

