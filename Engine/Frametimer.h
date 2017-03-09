#pragma once

#include <chrono>

class Frametimer
{
public:
	Frametimer();
	~Frametimer();

	float SetMark();
	std::chrono::steady_clock::time_point last;
};

