#include "../../include/MemoryInfo.h"
#include <windows.h>

unsigned long long MemoryInfo::getTotalMemory() {
    MEMORYSTATUSEX mem{};
    mem.dwLength = sizeof(mem);

    GlobalMemoryStatusEx(&mem);

    return mem.ullTotalPhys;
}

unsigned long long MemoryInfo::getAvailableMemory() {
    MEMORYSTATUSEX mem{};
    mem.dwLength = sizeof(mem);

    GlobalMemoryStatusEx(&mem);

    return mem.ullAvailPhys;
}

unsigned long long MemoryInfo::getUsedMemory() {
    MEMORYSTATUSEX mem{};
    mem.dwLength = sizeof(mem);
    GlobalMemoryStatusEx(&mem);

    return mem.ullTotalPhys - mem.ullAvailPhys;
}