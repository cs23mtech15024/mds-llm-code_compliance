// ------ Compliant
// Seed: Non-compliant header: int retry_limit = 3;   // Compliant header: extern int retry_limit;
// Context: Header contains only declarations; definitions moved to implementation.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (extern usage / header definitions).
//  - cppreference: One Definition Rule / Definitions and ODR (header/definition guidance).
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in the implementation section.

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int retry_limit;
extern int retry_limit; // declaration only

// Function prototype only (no definition in header)
bool attempt_with_retries(const std::string &op);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int retry_limit = 3; // COMPLIANT: definition in implementation file

bool attempt_with_retries(const std::string &op) {
    for (int i = 0; i < retry_limit; ++i) {
        std::cout << "[C] attempt_with_retries: op=" << op << " try=" << (i+1) << '\n';
        if (i == retry_limit - 1) return true;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    return false;
}

int main() {
    bool ok = attempt_with_retries("heartbeat");
    std::cout << "[C] operation result: " << (ok ? "success" : "failure") << " retry_limit=" << retry_limit << '\n';
    return 0;
}