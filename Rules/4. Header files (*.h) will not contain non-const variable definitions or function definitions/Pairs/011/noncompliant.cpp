// ------ Non-Compliant
// Seed: Non-compliant header: int timeout_ms = 5000;   // Compliant header: extern int timeout_ms;
// Context: Demonstration of a header that improperly defines a non-const global timeout and a non-inline helper.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?".
//  - cppreference: One Definition Rule / Definitions and ODR.
//  - PVS-Studio guidance: rules and warnings about definitions in headers.
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <chrono>
#include <thread>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int timeout_ms = 5000;
int timeout_ms = 5000; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function definition in header
bool check_timeout(int elapsed_ms) {
    // simple deterministic check using header-defined timeout_ms
    if (elapsed_ms >= timeout_ms) {
        std::cout << "[NC] check_timeout: elapsed=" << elapsed_ms << " >= timeout_ms=" << timeout_ms << '\n';
        return true;
    }
    std::cout << "[NC] check_timeout: elapsed=" << elapsed_ms << " < timeout_ms=" << timeout_ms << '\n';
    return false;
}
// ---------------------------------------------------------------------------

int main() {
    // simulate two deterministic steps with sleeps
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    bool t1 = check_timeout(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    bool t2 = check_timeout(6);
    std::cout << "[NC] t1=" << t1 << " t2=" << t2 << " timeout_ms=" << timeout_ms << '\n';
    return 0;
}