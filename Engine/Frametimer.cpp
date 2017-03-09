#include "Frametimer.h"



Frametimer::Frametimer()
{
	last = std::chrono::steady_clock::now();
}


Frametimer::~Frametimer()
{
}

float Frametimer::SetMark()
{
	const std::chrono::steady_clock::time_point old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> dt = last - old;
	return dt.count();
}
