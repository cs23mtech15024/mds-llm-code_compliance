// Context: Watchdog timer period

// Seed 099 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _watchdog_ms = 5000; // NC
    std::cout << "watchdog=" << _watchdog_ms << "ms\n";
    return 0;
}