#include "../include/ProcessInfo.h"

ProcessInfo::ProcessInfo(unsigned long pid, std::string name, double CPUUsage, unsigned long long memoryUsage): PID(pid), name(name), CPUUsage(CPUUsage), memUsage(memoryUsage) {}

unsigned long ProcessInfo::getPID() const {
    return PID;
}

std::string ProcessInfo::getName() const{
    return name;
}

double ProcessInfo::getCPUUsage() const{
    return CPUUsage;
}

unsigned long long ProcessInfo::getMemUsage() const{
    return memUsage;
}