// ------ Non-Compliant
// Seed: Non-compliant header: bool ready = false;   // Compliant header: extern bool ready;
// Context: Adapted demo showing a header that incorrectly holds definitions.
// Source: MISRA C++:2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
//         cppreference: One Definition Rule and header best practices.
// Violation: Header contains a non-const variable definition and a non-inline function definition (both should be declarations only in headers).

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined for demo) -------------------
// NON-COMPLIANT: header contains definitions (violation)
// Seed (must appear in header): bool ready = false;   // NON-COMPLIANT header-level definition
bool ready = false; // NON-COMPLIANT: non-const variable defined in header

// NON-COMPLIANT: function definition in header (non-inline)
void notify(const char *msg) {
    // simple deterministic notification to stdout (header should not define non-inline functions)
    std::cout << "[NC] notify: " << msg << " ready=" << (ready ? "true" : "false") << '\n';
}
// ---------------------------------------------------------------------

// Implementation code uses header-defined items
void initialize_system() {
    // set ready and notify
    ready = true;
    notify("system initialized");
}

void shutdown_system() {
    notify("system shutting down");
    ready = false;
}

int main() {
    initialize_system();
    // deterministic delay to simulate processing
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    shutdown_system();
    std::cout << "[NC] final ready = " << (ready ? "true" : "false") << '\n';
    return 0;
}