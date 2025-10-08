// ------ Compliant
// Seed: Non-compliant header: int timeout_ms = 5000;   // Compliant header: extern int timeout_ms;
// Context: Header contains only declarations; definitions moved to implementation.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?".
//  - cppreference: One Definition Rule / Definitions and ODR.
//  - PVS-Studio guidance: rules and warnings about definitions in headers.
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in the implementation area.

#include <iostream>
#include <chrono>
#include <thread>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int timeout_ms;
extern int timeout_ms; // declaration only

// Function prototype only (no definition in header)
bool check_timeout(int elapsed_ms);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int timeout_ms = 5000; // COMPLIANT: definition in implementation file

bool check_timeout(int elapsed_ms) {
    if (elapsed_ms >= timeout_ms) {
        std::cout << "[C] check_timeout: elapsed=" << elapsed_ms << " >= timeout_ms=" << timeout_ms << '\n';
        return true;
    }
    std::cout << "[C] check_timeout: elapsed=" << elapsed_ms << " < timeout_ms=" << timeout_ms << '\n';
    return false;
}

int main() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    bool t1 = check_timeout(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    bool t2 = check_timeout(6);
    std::cout << "[C] t1=" << t1 << " t2=" << t2 << " timeout_ms=" << timeout_ms << '\n';
    return 0;
}