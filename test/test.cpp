#include <iostream>
#include "..\src\statys.h"

int main() {
    statys::sys_mem sys_memory;

    while (true) {
        int *i = new int;
    
        if (sys_memory.get_usage_as_percent() > 75) {
            std::cout << "System memory usage has exceeded 75%. Breaking from loop.\n";
            break;
        }
    }

    return 0;
}