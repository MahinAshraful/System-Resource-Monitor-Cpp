#ifndef MEMORYINFO_H
#define MEMORYINFO_H

class MemoryInfo {
public:
    unsigned long long getTotalMemory();
    unsigned long long getUsedMemory();
    unsigned long long getAvailableMemory();
};

#endif