// ------ Non-Compliant
// Seed: Non-compliant header: int session_id = 0;   // Compliant header: extern int session_id;
// Context: Example demonstrating a header that defines a non-const global session id and a non-inline helper function.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?". 
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
//   - PVS-Studio / static analyzer guidance: warnings about definitions in headers and header best practices.
// Violation: Header-like region contains a non-const global definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int session_id = 0;
int session_id = 0; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function definition in header (should be prototype only)
void start_session_for(const std::string &who) {
    ++session_id;
    std::cout << "[NC] start_session_for: " << who << " session=" << session_id << '\n';
}
// ---------------------------------------------------------------------------

void run_workflow() {
    start_session_for("OperatorA");
    std::this_thread::sleep_for(std::chrono::milliseconds(4));
    start_session_for("OperatorB");
}

int main() {
    run_workflow();
    std::cout << "[NC] final session_id=" << session_id << '\n';
    return 0;
}