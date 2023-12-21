#include "Timer.h"

Timer::Timer() : m_running(false) {}

void Timer::start()
{
    m_startTime = chrono::high_resolution_clock::now();
    m_running = true;
}

void Timer::stop()
{
    m_endTime = chrono::high_resolution_clock::now();
    m_running = false;
}

double Timer::elapsedMilliseconds() const
{
    chrono::time_point<chrono::high_resolution_clock> endTime;

    if (m_running)
    {
        endTime = chrono::high_resolution_clock::now();
    }
    else
    {
        endTime = m_endTime;
    }

    return chrono::duration_cast<chrono::milliseconds>(endTime - m_startTime).count();
}

double Timer::elapsedSeconds() const
{
    return elapsedMilliseconds() / 1000.0;
}