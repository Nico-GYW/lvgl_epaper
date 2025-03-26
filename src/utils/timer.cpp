#include "timer.hpp"

#include <Arduino.h>

double Timer::elapsed() const
{
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

Timer::Timer(std::string_view tag) : tag(tag), start(std::chrono::high_resolution_clock::now())
{
}

void Timer::stop()
{
    stopped = true;
    double duration = elapsed();
    Serial.printf("[%s] Elapsed: %.2f ms\n", tag.c_str(), duration);
}

Timer::~Timer()
{
    if (!stopped)
        stop();
}
