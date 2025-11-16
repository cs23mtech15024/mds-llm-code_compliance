// Context: RFID reader timeout configuration

// -------- Compliant Program (prog_036_c.cpp)
// Context: RFID reader timeout behavior — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed036_timeout_ms = 250;
bool seed036_should_retry(int elapsed) { return elapsed < seed036_timeout_ms; }

namespace rfid_c {

int simulate_attempts(const int (&times)[5]) {
    int retries = 0;
    for (int t : times) {
        bool retry = seed036_should_retry(t);
        std::cout << "elapsed=" << t
                  << " retry=" << (retry ? "Y" : "N") << "\n";
        if (retry) ++retries;
    }
    return retries;
}

int sum(const int (&arr)[5]) {
    int s = 0;
    for (int v : arr) s += v;
    return s;
}

} // namespace rfid_c

int main() {
    using namespace rfid_c;
    const int t[5] = {50,100,200,260,300};
    int r = simulate_attempts(t);
    std::cout << "retries=" << r << " sum=" << sum(t) << "\n";
    return 0;
}
