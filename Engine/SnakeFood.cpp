#include "SnakeFood.h"



SnakeFood::SnakeFood()
{
}


SnakeFood::~SnakeFood()
{
}

void SnakeFood::InitFood(const GridLocation & loc)
{
	Location = loc;
	Col = Colors::Green;
}

void SnakeFood::Draw(Board & brd)
{
	brd.DrawCell(Location, Col);
}

const GridLocation & SnakeFood::GetLocation() const
{
	return Location;
}

void SnakeFood::SetLocation(GridLocation & loc)
{
	Location = loc;
}

bool SnakeFood::FoodEaten(GridLocation & loc)
{
	if (loc == Location)
		return true;
	else
		return false;
}
