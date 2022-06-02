#ifndef STATYS_H
#define STATYS_H

#include <windows.h>

namespace statys {
    class SysMemory {
        public:
            int usageAsPercent();
            /// Returns the amount of available physical memory in kilobytes.
            DWORDLONG availablePhysicalMemory();
            /// Returns the total amount of physical memory in kilobytes.
            DWORDLONG totalPhysicalMemory();
    };
}

#endif  /* STATYS_H */