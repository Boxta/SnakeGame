#pragma once

#include "GridLocation.h"
#include "Graphics.h"
#include "Board.h"

class SnakeFood
{
public:
	SnakeFood();
	~SnakeFood();
	void InitFood(const GridLocation& loc);
	void Draw(Board& brd);
	const GridLocation& GetLocation() const;
	void SetLocation(GridLocation& loc);
	bool FoodEaten(GridLocation& loc);
	Color Col;

	GridLocation Location;
};