#include <iostream>

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

    return 0;
}