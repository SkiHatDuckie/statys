#include "statys.h"
#include <windows.h>

using namespace statys;

int sys_mem::get_usage_as_percent() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return statex.dwMemoryLoad;
}