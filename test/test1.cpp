#include <windows.h>
//#include <tchar.h>
#include <chrono>
#include <iostream>

// The total number of durations to store in an array.
const int DURATIONS_SIZE = 10000;

// Wastes memory.
// Precondition: length of `durations` > 0, 
// `size` is the same number as the size of `durations`.
int *waste_memory_control(int *durations) {
    using namespace std::literals;
    using namespace std::chrono;

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);

    time_point<std::chrono::steady_clock> start = steady_clock::now();
    int i = 0;

    while(true) {
        int *a = new int;

        // Check system memory usage to see if it's safe to continue.
        GlobalMemoryStatusEx(&statex);
        if (statex.dwMemoryLoad > 80) {
            std::cout << "System memory usage has exceeded 80%. Breaking from loop.\n";
            break;
        }

        // Log duration of iteration in nanoseconds.
        durations[i] = (steady_clock::now() - start) / 1ns;
        start = steady_clock::now();
        i++;
        if (i == DURATIONS_SIZE) { break; }
    }

    return durations;
}

// Wastes memory and does not check if it should.
// WARNING: THIS FUNCTION CAN STALL YOUR COMPUTER IF NOT CAREFUL!
int *waste_memory_no_check(int *durations) {
    using namespace std::literals;
    using namespace std::chrono;

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);

    time_point<std::chrono::steady_clock> start = steady_clock::now();
    int i = 0;

    while(true) {
        int *a = new int;

        // Log duration of iteration in nanoseconds.
        durations[i] = (steady_clock::now() - start) / 1ns;
        start = steady_clock::now();
        i++;
        if (i == DURATIONS_SIZE) { break; }
    }

    return durations;
}

// Returns the average duration of time in milliseconds
double get_avg_duration(int *durations) {
    double sum = 0;
    for (int i = 0; i < DURATIONS_SIZE; i++) {
        sum += durations[i];
    }
    return sum / DURATIONS_SIZE;
}

int main() {
    std::cout << "Running waste_memory_control()\n";
    int *durations = waste_memory_control(new int[DURATIONS_SIZE]);
    std::cout << "Average: ";
    std::cout << get_avg_duration(durations) << "ns/iteration\n";

    std::cout << "Running waste_memory_no_check()\n";
    durations = waste_memory_no_check(new int[DURATIONS_SIZE]);
    std::cout << "Average: ";
    std::cout << get_avg_duration(durations) << "ns/iteration\n";

    return 0;
}