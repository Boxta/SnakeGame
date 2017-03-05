#pragma once
#include "Board.h"
class Snake
{
public:
	Snake(const GridLocation& loc);
	~Snake();

	void MoveBy(GridLocation& delta_loc);
	void Grow();
	void Draw( Board& brd);

private:
	class Segment
	{
	public:
		void InitHead(const GridLocation& loc);
		void InitBody();
		void MoveHeadSegment(const GridLocation& loc);
		void BodySegmentFollow(const Segment& next);
		void Draw(Board& brd);
	private:
		GridLocation SegmentLocation;
		Color SegmentColor;
	};

private:
	static constexpr int nSegmentsMax = 100;
	int nSegmentsUsed = 1;
	Segment SegmentArray[nSegmentsMax];

};

