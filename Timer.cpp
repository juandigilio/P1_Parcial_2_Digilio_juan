#include "Timer.h"

Timer::Timer()
{
    lastTime = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
}

bool Timer::ElapsedTime(int interval)
{ 
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();

    if (deltaTime >= interval)
    {
        lastTime = currentTime;
        return true;
    }

    return false; 
}
