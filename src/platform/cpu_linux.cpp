#include "../../include/CPUInfo.h"
#include <fstream>
#include <string>

CPUInfo::CPUInfo() {
    readCPUData(prevIdleTime, prevTotalTime);
}


void CPUInfo::readCPUData(long long& idleTime, long long& totalTime) {
    std::ifstream file("/proc/stat");
    std::string cpuLabel;
    long long user, nice, system, idle, iowait, irq, softirq, steal;

    file >> cpuLabel >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;

    idleTime = idle + iowait;
    totalTime = user + nice + system + idle + iowait + irq + softirq + steal;
}

double CPUInfo::getUsagePercent() {
    long long idleTime, totalTime;
    readCPUData(idleTime, totalTime);

    long long idleDelta = idleTime - prevIdleTime;
    long long totalDelta = totalTime - prevTotalTime;

    prevIdleTime = idleTime;
    prevTotalTime = totalTime;

    if (totalDelta == 0) return 0.0;

    double usage = (1.0 - static_cast<double>(idleDelta) / totalDelta) * 100.0;
    return usage;
}