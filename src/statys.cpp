#include "statys.h"
#include <windows.h>

using namespace statys;

DWORDLONG toKilobytes(DWORDLONG bytes) {
    return bytes / 1024;
}

int SysMemory::usageAsPercent() {
    GlobalMemoryStatusEx(&_statex);
    return _statex.dwMemoryLoad;
}

DWORDLONG SysMemory::availablePhysicalMemory() {
    GlobalMemoryStatusEx(&_statex);
    return toKilobytes(_statex.ullAvailPhys);
}

DWORDLONG SysMemory::totalPhysicalMemory() {
    GlobalMemoryStatusEx(&_statex);
    return toKilobytes(_statex.ullTotalPhys);
}