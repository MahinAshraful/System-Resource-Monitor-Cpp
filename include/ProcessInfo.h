#ifndef PROCESSINFO_H
#define PROCESSINFO_H

#include <string>

class ProcessInfo {
public:
    ProcessInfo() = default;
    ProcessInfo(unsigned long pid, std::string name, double cpuUsage, unsigned long long memoryUsage);

    unsigned long getPID() const;
    std::string getName() const;
    double getCPUUsage() const;
    unsigned long long getMemUsage() const;

private:
    unsigned long PID;
    std::string name;
    double CPUUsage;
    unsigned long long memUsage;
};

#endif