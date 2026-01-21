C++ based system resource monitor

to run : 

windows
g++ -std=c++17 -o sysmon main.cpp src/ProcessInfo.cpp src/platform/cpu_windows.cpp src/platform/memory_windows.cpp src/platform/process_windows.cpp -lpsapi

linux
g++ -std=c++17 -o sysmon main.cpp src/ProcessInfo.cpp src/platform/cpu_linux.cpp src/platform/memory_linux.cpp src/platform/process_linux.cpp

./sysmon