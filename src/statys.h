#ifndef STATYS_H
#define STATYS_H

#include <windows.h>

namespace statys {
    class SysMemory {
        public:
            // Store the size of `_statex` for version compatibility.
            SysMemory() { _statex.dwLength = sizeof(_statex); }
            int usageAsPercent();
            /// Returns the amount of available physical memory in kilobytes.
            DWORDLONG availablePhysicalMemory();
            /// Returns the total amount of physical memory in kilobytes.
            DWORDLONG totalPhysicalMemory();
        private:
            MEMORYSTATUSEX _statex;
    };
}

#endif  /* STATYS_H */