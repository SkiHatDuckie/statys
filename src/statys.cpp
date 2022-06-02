#include "statys.h"
#include <windows.h>

using namespace statys;

DWORDLONG toKilobytes(DWORDLONG bytes) {
    return bytes / 1024;
}

int SysMemory::usageAsPercent() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return statex.dwMemoryLoad;
}

DWORDLONG SysMemory::availablePhysicalMemory() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return toKilobytes(statex.ullAvailPhys);
}

DWORDLONG SysMemory::totalPhysicalMemory() {
    MEMORYSTATUSEX _statex;
    _statex.dwLength = sizeof(_statex);
    GlobalMemoryStatusEx(&_statex);
    return toKilobytes(_statex.ullTotalPhys);
}