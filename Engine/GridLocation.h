#pragma once
struct GridLocation
{
	void Add(const GridLocation& new_loc)
	{
		x += new_loc.x;
		y += new_loc.y;
	}
	bool operator==(const GridLocation& new_loc) const
	{
		if (x == new_loc.x && 
			y == new_loc.y)
		{
			return true;
		}
		else
		{
			return false;
		}
		/* Chilli Solution
		return x == new_loc.x &&
			y == new_loc.y;
		*/
	}
	int x;
	int y;
};

