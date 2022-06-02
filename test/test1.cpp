#include <windows.h>
#include <chrono>
#include <iostream>
#include "..\src\statys.h"

// The total number of durations to store in an array.
const int ITERATIONS = 10000;

int *benchmarkStatysStatex(int *durations) {
    using namespace std::literals;
    using namespace std::chrono;

    statys::SysMemory sys_memory;
    time_point<std::chrono::steady_clock> start = steady_clock::now();

    for (int i = 0; i < ITERATIONS; i++) {
        sys_memory.usageAsPercent();
        sys_memory.availablePhysicalMemory();
        sys_memory.totalPhysicalMemory();

        // Log duration of iteration in nanoseconds.
        durations[i] = (steady_clock::now() - start) / 1ns;
        start = steady_clock::now();
    }

    return durations;
}

// Returns the average duration of time in milliseconds
double getAvgDuration(int *durations) {
    double sum = 0;
    for (int i = 0; i < ITERATIONS; i++) {
        sum += durations[i];
    }
    return sum / ITERATIONS;
}

int main() {
    std::cout << "Running benchmarkStatysStatex()\n";
    int *durations = benchmarkStatysStatex(new int[ITERATIONS]);
    std::cout << "Average: ";
    std::cout << getAvgDuration(durations) << "ns/iteration\n";

    return 0;
}