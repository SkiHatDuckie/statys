#include "statys.h"
#include <windows.h>

using namespace statys;

int SysMemory::getUsageAsPercent() {
    _statex.dwLength = sizeof(_statex);
    GlobalMemoryStatusEx(&_statex);
    return _statex.dwMemoryLoad;
}