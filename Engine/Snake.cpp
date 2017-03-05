#include "Snake.h"



Snake::Snake(const GridLocation& loc)
{
	SegmentArray[0].InitHead(loc);
}

Snake::~Snake()
{
}

void Snake::MoveBy(GridLocation & delta_loc)
{
	//Foreach Segment Currently Used That is Not The Head
	for (int i = nSegmentsUsed - 1; i > 0; i--)
	{
		SegmentArray[i].BodySegmentFollow(SegmentArray[i - 1]);
	}
	SegmentArray[0].MoveHeadSegment(delta_loc);
}

void Snake::Grow()
{
	if (nSegmentsUsed < nSegmentsMax)
	{
		SegmentArray[nSegmentsUsed].InitBody();
		nSegmentsUsed++;
	}
}

void Snake::Draw(Board & brd)
{
	for (int x = 0; x < nSegmentsUsed; x++)
	{
		SegmentArray[x].Draw(brd);
	}
}

void Snake::Segment::InitHead(const GridLocation & in_loc)
{
	SegmentLocation = in_loc;
	SegmentColor = Colors::Yellow;
}

void Snake::Segment::InitBody()
{
	SegmentColor = Colors::Magenta;
}

void Snake::Segment::MoveHeadSegment(const GridLocation & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	SegmentLocation.Add(delta_loc);
}

void Snake::Segment::BodySegmentFollow(const Segment & next)
{
	SegmentLocation = next.SegmentLocation;
}

void Snake::Segment::Draw(Board & brd)
{
	brd.DrawCell(SegmentLocation, SegmentColor);
}
