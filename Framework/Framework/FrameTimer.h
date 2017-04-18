#pragma once

#include <chrono>

class FrameTimer {
public:
	FrameTimer();
	float Mark();
private:
	std::chrono::system_clock::time_point curtime;
	std::chrono::system_clock::time_point lasttime;
};