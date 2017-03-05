#include "Snake.h"



Snake::Snake(const GridLocation& loc)
{
	segments[0].InitHead(loc);
}


Snake::~Snake()
{
}

void Snake::MoveBy(GridLocation & delta_loc)
{
	//Foreach Segment Currently Used That is Not The Head
	for (int i = nSegmentsUsed - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegmentsUsed < nSegmentsMax)
	{
		segments[nSegmentsUsed].InitBody();
		nSegmentsUsed++;
	}
}

void Snake::Draw(Board & brd)
{
	for (int x = 0; x < nSegmentsUsed; x++)
	{
		segments[x].Draw(brd);
	}
}
//coment
void Snake::Segment::InitHead(const GridLocation & in_loc)
{
	loc = in_loc;
	c = Colors::Yellow;
}

void Snake::Segment::InitBody()
{
	c = Colors::Magenta;
}

void Snake::Segment::MoveBy(const GridLocation & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
}
