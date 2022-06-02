#include <iostream>
#include "..\src\statys.h"

int main() {
    statys::SysMemory sys_memory;

    while (true) {
        int *i = new int;

        if (sys_memory.usageAsPercent() > 70) {
            std::cout << "System memory usage has exceeded 70%. Breaking from loop.\n";

            DWORDLONG avail_memory = sys_memory.availablePhysicalMemory();
            DWORDLONG total_memory = sys_memory.totalPhysicalMemory();
            std::cout << avail_memory << " KB available | " << total_memory << " KB total\n";

            break;
        }
    }

    return 0;
}