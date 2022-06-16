#include <iostream>
#include "..\src\statys.h"

int main() {
    statys::SysMemory sys_memory;
    statys::ProcMemory proc_memory;

    while (true) {
        // Constantly create new pointers to memory without deleting them. 
        // This would lead to the program using up all RAM and promptly blue-screening the computer.
        int *i = new int;

        if (sys_memory.usageAsPercent() > 70) {
            // Break from loop so that pointers are taken out of scope (deleted automatically by the compiler).
            std::cout << "System memory usage has exceeded 70%. Breaking from loop.\n";

            DWORDLONG avail_memory = sys_memory.availablePhysicalMemory();
            DWORDLONG total_memory = sys_memory.totalPhysicalMemory();
            std::cout << avail_memory << " KB available | " << total_memory << " KB total\n";

            SIZE_T working_set = proc_memory.workingSet();
            std::cout << working_set << " KB in use by process\n";

            break;
        }
    }

    return 0;
}