#pragma once
struct GridLocation
{
	void Add(const GridLocation& new_loc)
	{
		x += new_loc.x;
		y += new_loc.y;
	}
	int x;
	int y;
};

