#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include "include/CPUInfo.h"
#include "include/MemoryInfo.h"
#include "include/ProcessManager.h"

int main(){
    #ifdef _WIN32
        std::cout <<"OS detected at compile time: Windows\n";
    #elif defined(__linux__)
        std::cout <<"OS detected at compile time: Linux\n";
    #elif defined(__APPLE__)
        std::cout <<"OS detected at compile time: MacOS\n";
    #else
        std::cout <<"OS detected at compile time: Unknown\n";
    #endif

    CPUInfo cpu;
    MemoryInfo mem;
    ProcessManager pm;

    //memory
    unsigned long long gb = 1024ULL * 1024 * 1024;
    std::cout << "Total Memory: " << mem.getTotalMemory() / gb << "GB" << '\n';
    std::cout << "Used Memory: " << mem.getUsedMemory() / gb << "GB" << '\n';
    std::cout << "Available Memory: " << mem.getAvailableMemory() / gb << "GB" << '\n';

    //cpu
    //set small delay before first reading
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    for (int i = 0; i < 10; i++){
        std::cout << "CPU USAGE: " << static_cast<int>(std::lround(cpu.getUsagePercent())) << "%" << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    //processes
    std::vector<ProcessInfo> topProcs = pm.getTopProcesses(10);
    for (const auto& proc : topProcs) {
        std::cout << proc.getName() << " - " << proc.getMemUsage() / (1024 * 1024) << " MB\n";
    }

    return 0;
}