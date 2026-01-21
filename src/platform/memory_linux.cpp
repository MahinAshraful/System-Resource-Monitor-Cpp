#include "../../include/MemoryInfo.h"
#include <fstream>
#include <string>

unsigned long long MemoryInfo::getTotalMemory() {
    std::ifstream file("/proc/meminfo");
    std::string label;
    unsigned long long value;
    std::string unit;

    while (file >> label >> value >> unit) {
        if (label == "MemTotal:") {
            return value * 1024;  // kb to bytes
        }
    }
    return 0;
}

unsigned long long MemoryInfo::getAvailableMemory() {
    std::ifstream file("/proc/meminfo");
    std::string label;
    unsigned long long value;
    std::string unit;

    while (file >> label >> value >> unit){
        if (label == "MemAvailable:") {
            return value * 1024;
        }
    }
    return 0;
}

unsigned long long MemoryInfo::getUsedMemory() {
    return getTotalMemory() - getAvailableMemory();
}