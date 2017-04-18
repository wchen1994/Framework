#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	lasttime = curtime = std::chrono::system_clock::now();
}

float FrameTimer::Mark()
{
	curtime = std::chrono::system_clock::now();
	return (curtime - lasttime).count();
}
