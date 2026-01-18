#include <iostream>
#include <thread>
#include <chrono>
#include "include/CPUInfo.h"

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

    //set small delay before first reading
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    for (int i = 0; i < 10; i++){
        std::cout << "CPU USAGE: " << cpu.getUsagePercent() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}