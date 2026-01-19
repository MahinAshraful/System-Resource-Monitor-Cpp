#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <vector>
#include "ProcessInfo.h"

class ProcessManager {
public:
    std::vector<ProcessInfo> getTopProcesses(int count);

private:
    std::vector<ProcessInfo> getAllProcesses(); 
};

#endif