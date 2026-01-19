#include "../../include/ProcessManager.h"
#include <windows.h>
#include <tlhelp32.h>
#include <algorithm>
#include <iostream>
#include <psapi.h>
#include <string>

unsigned long long getProcessMemory(unsigned long pid) {
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (!hProcess) return 0;

    PROCESS_MEMORY_COUNTERS pmc{};
    unsigned long long mem = 0;

    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
        mem = pmc.WorkingSetSize;
    }

    CloseHandle(hProcess);
    return mem;
}

std::vector<ProcessInfo> ProcessManager::getAllProcesses() {
    std::vector<ProcessInfo> processes;

    //use CreateToolhelp32Snapshot to get process list
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    
    PROCESSENTRY32 pe{};
    pe.dwSize = sizeof(pe);

    // loop through with Process32First / Process32Next
    Process32First(snapshot, &pe);
    while (true){
        std::string name(pe.szExeFile);

        unsigned long pid = pe.th32ProcessID;
        double cpuUsage = 0.0;
        unsigned long long memUsage = getProcessMemory(pid);

        processes.emplace_back(pid, name, cpuUsage, memUsage);

        if(!Process32Next(snapshot, &pe)){
            break;
        }
    }
    CloseHandle(snapshot);
    return processes;
}

std::vector<ProcessInfo> ProcessManager::getTopProcesses(int count) {
    std::vector<ProcessInfo> procs = getAllProcesses();

    std::sort(procs.begin(), procs.end(), [](const ProcessInfo& a, const ProcessInfo& b) {
        return a.getMemUsage() > b.getMemUsage();
    });

    if (static_cast<size_t>(count) < procs.size()) {
        procs.resize(count);
    }

    return procs;
}