#include <iostream>
#include "..\src\statys.h"

int main() {
    statys::SysMemory sys_memory;

    while (true) {
        int *i = new int;
    
        if (sys_memory.getUsageAsPercent() > 75) {
            std::cout << "System memory usage has exceeded 75%. Breaking from loop.\n";
            break;
        }
    }

    return 0;
}