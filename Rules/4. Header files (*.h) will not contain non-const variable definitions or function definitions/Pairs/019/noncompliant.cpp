// ------ Non-Compliant
// Seed: Non-compliant header: bool debug_flag = false;   // Compliant header: extern bool debug_flag;
// Context: Header incorrectly defines a global debug flag and a helper function.
// Provenance:
//   - StackOverflow Q#1433204: “How do I use extern to share variables between source files?”
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
//   - PVS-Studio / static analyzer guidance: “Avoid variable definitions in headers”.
// Violation: Header-like region contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): bool debug_flag = false;
bool debug_flag = false; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function definition in header (should be prototype only)
void log_message(const std::string &msg) {
    if (debug_flag) {
        std::cout << "[NC-DEBUG] " << msg << '\n';
    }
    else {
        std::cout << "[NC] (quiet mode) " << msg << '\n';
    }
}
// ---------------------------------------------------------------------------

int main() {
    log_message("Starting diagnostics...");
    debug_flag = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    log_message("Diagnostics completed.");
    return 0;
}