#ifndef CPUINFO_H
#define CPUINFO_H

class CPUInfo {
public:
    CPUInfo();
    double getUsagePercent();

private:
    long long prevIdleTime;
    long long prevTotalTime;

    void readCPUData(long long& idleTime, long long& totalTime);
};

#endif