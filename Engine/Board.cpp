#include "Board.h"



Board::Board(Graphics& gfx)
	:
	graphics(gfx)
{

}


Board::~Board()
{
}

int Board::GetGridWidth() const
{
	return Width;
}

int Board::GetGridHeight() const
{
	return Height;
}

void Board::DrawCell(GridLocation& new_loc, Color c)
{
	assert(new_loc.x >= 0);
	assert(new_loc.y >= 0);
	assert(new_loc.x < Width);
	assert(new_loc.y < Height);

	for (int x = 0; x < (Width * Dimension) + (CellPadding * Width); x++)
	{
		graphics.PutPixel(Off_X_Position + x, Off_Y_Position - 1, 255, 0, 0);
		graphics.PutPixel(Off_X_Position + x, Off_Y_Position + (CellPadding * Height) + (Height * Dimension) - 1, 255, 0, 0);
	}
	for (int y = 0; y < (Height * Dimension) + (CellPadding * Height); y++)
	{
		graphics.PutPixel(Off_X_Position - 1, Off_Y_Position + y, 255, 0, 0);
		graphics.PutPixel(Off_X_Position + (Width * Dimension) + (CellPadding * Width) - 1, Off_Y_Position + y, 255, 0, 0);
	}

	graphics.DrawRectDim(
		Off_X_Position + (CellPadding * new_loc.x) + (new_loc.x * Dimension),
		Off_Y_Position + (CellPadding * new_loc.y) + (new_loc.y * Dimension),
		Dimension,
		Dimension,
		c);
}
