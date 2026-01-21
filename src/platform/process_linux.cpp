#include "../../include/ProcessManager.h"
#include <fstream>
#include <string>                                                                                                                                                                                                                                                                                                               
#include <algorithm>
#include <filesystem>


namespace fs = std::filesystem;

std::vector<ProcessInfo> ProcessManager::getAllProcesses() {
    std::vector<ProcessInfo> processes;
    for (const auto& entry : fs::directory_iterator("/proc")) {
        std::string filename = entry.path().filename().string();

        // Skip if not a number (only PID folders are numeric)
        if (!std::all_of(filename.begin(), filename.end(), ::isdigit)) {
            continue;
        }

        unsigned long pid = std::stoul(filename);
        std::string name = "";
        unsigned long long memUsage = 0;

        std::ifstream commFile(entry.path() / "comm");
        if (commFile) {
            std::getline(commFile, name);
        }

        std::ifstream statmFile(entry.path() / "statm");
        if (statmFile) {
            unsigned long long pages;
            statmFile >> pages;
            memUsage = pages * 4096; 
        }

        processes.emplace_back(pid, name, 0.0, memUsage);
    }

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