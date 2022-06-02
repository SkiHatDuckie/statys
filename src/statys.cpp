#include "statys.h"
#include <windows.h>

using namespace statys;

// Converts some numeric type representing an amount of bytes into kilobytes.
template<typename T>
T toKilobytes(T bytes) {
    return bytes / 1024;
}

int SysMemory::usageAsPercent() {
    GlobalMemoryStatusEx(&_statex);
    return _statex.dwMemoryLoad;
}

DWORDLONG SysMemory::availablePhysicalMemory() {
    GlobalMemoryStatusEx(&_statex);
    return toKilobytes<DWORDLONG>(_statex.ullAvailPhys);
}

DWORDLONG SysMemory::totalPhysicalMemory() {
    GlobalMemoryStatusEx(&_statex);
    return toKilobytes<DWORDLONG>(_statex.ullTotalPhys);
}

SIZE_T ProcMemory::workingSet() {
    if (GetProcessMemoryInfo(_hProcess, &_pmc, sizeof(_pmc))) {
        return toKilobytes<SIZE_T>(_pmc.WorkingSetSize);
    }
    return -1;
}