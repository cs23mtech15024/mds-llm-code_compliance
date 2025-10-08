// ------ Non-Compliant
// Seed: Non-compliant header: int retry_limit = 3;   // Compliant header: extern int retry_limit;
// Context: Demonstration of a header that incorrectly defines a non-const global retry limit and a non-inline helper.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (extern usage / header definitions).
//  - cppreference: One Definition Rule / Definitions and ODR (header/definition guidance).
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int retry_limit = 3;
int retry_limit = 3; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function definition in header
bool attempt_with_retries(const std::string &op) {
    for (int i = 0; i < retry_limit; ++i) {
        std::cout << "[NC] attempt_with_retries: op=" << op << " try=" << (i+1) << '\n';
        // deterministic fake success on last attempt
        if (i == retry_limit - 1) return true;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    return false;
}
// ---------------------------------------------------------------------------

int main() {
    bool ok = attempt_with_retries("heartbeat");
    std::cout << "[NC] operation result: " << (ok ? "success" : "failure") << " retry_limit=" << retry_limit << '\n';
    return 0;
}