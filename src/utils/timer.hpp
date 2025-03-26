#pragma once

#include <chrono>
#include <string>

/**
 * A simple timer class to measure the elapsed time between two points.
 * Stops and prints the elapsed time when the object is destroyed.
 */
class Timer
{
    std::string tag;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    bool stopped = false;

    /**
     * Get the elapsed time in milliseconds.
     */
    double elapsed() const;

public:
    explicit Timer(std::string_view tag);

    /**
     * Stop the timer and print the elapsed time before the object is destroyed.
     */
    void stop();

    ~Timer();
};
