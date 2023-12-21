#ifndef Timer_H
#define Timer_H

#include <chrono>

using namespace std;

class Timer
{
public:
    Timer();
    void start();
    void stop();
    double elapsedMilliseconds() const;
    double elapsedSeconds() const;

private:
    chrono::time_point<chrono::high_resolution_clock> m_startTime;
    chrono::time_point<chrono::high_resolution_clock> m_endTime;
    bool m_running;
};

#endif