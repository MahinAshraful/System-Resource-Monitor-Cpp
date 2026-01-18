#include "../../include/CPUInfo.h"
#include <windows.h>

long long toLL(const FILETIME& ft){
    return (static_cast<long long>(ft.dwHighDateTime) << 32 | ft.dwLowDateTime);
}

CPUInfo::CPUInfo() {
    readCPUData(prevIdleTime, prevTotalTime);
}

void CPUInfo::readCPUData(long long& idleTime, long long& totalTime) {
    FILETIME idle, kernel, user;
    GetSystemTimes(&idle, &kernel, &user);
    //total time  = kernel + user
    //busy time = total time - idle
    //usage = busy time / total time
    idleTime = toLL(idle);
    totalTime = toLL(kernel) + toLL(user);

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
