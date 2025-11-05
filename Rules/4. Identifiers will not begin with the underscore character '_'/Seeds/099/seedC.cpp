// Context: Watchdog timer period

// Seed 099 — C: variable without underscore prefix
#include <iostream>
int main(){
    int watchdog_ms = 5000; // C
    std::cout << "watchdog=" << watchdog_ms << "ms\n";
    return 0;
}