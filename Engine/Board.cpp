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
	assert(new_loc.x > 0 &&
			new_loc.y > 0 &&
			new_loc.x < Dimension * Width &&
			new_loc.y < Dimension * Height);

	graphics.DrawRectDim(
		new_loc.x * Dimension,
		new_loc.y * Dimension,
		Dimension,
		Dimension,
		c);
}
