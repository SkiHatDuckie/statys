#ifndef STATYS_H
#define STATYS_H

#include <windows.h>

namespace statys {
    class SysMemory {
        public:
            int getUsageAsPercent();
        
        private:
            MEMORYSTATUSEX _statex;
    };
}

#endif  /* STATYS_H */