#pragma once

#include <windows.h>
#include <psapi.h>

namespace statys {
    /// Class containing various methods for grabbing system resource usage.
    class SysMemory {
        public:
            // Store the size of `_statex` for version compatibility.
            SysMemory() { _statex.dwLength = sizeof(_statex); }
            int usageAsPercent();
            /// Gets the amount of available physical memory in kilobytes.
            DWORDLONG availablePhysicalMemory();
            /// Gets the total amount of physical memory in kilobytes.
            DWORDLONG totalPhysicalMemory();
        private:
            MEMORYSTATUSEX _statex;
    };
    /// Class containing various methods for grabbing process resource usage.
    class ProcMemory {
        public:
            ProcMemory() {
                _hProcess = OpenProcess(
                    PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 
                    FALSE, 
                    GetCurrentProcessId());
            }
            /// Gets the current size of the working set of the process in kilobytes.
            /// Returns -1 if method was unsuccessful.
            SIZE_T workingSet();
        private:
            HANDLE _hProcess;
            PROCESS_MEMORY_COUNTERS _pmc;
    };
}