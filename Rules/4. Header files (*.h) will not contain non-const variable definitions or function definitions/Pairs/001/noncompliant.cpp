// ------ Non-Compliant
// Seed: Non-compliant header: int g_counter = 0;   // Compliant header: extern int g_counter;
// Context: Adapted example showing a header file that incorrectly contains definitions.
// Source: MISRA C++:2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
//         cppreference: One Definition Rule and header best practices.
// Violation: Header contains a non-const variable definition and a non-inline function definition (should be declarations only).

#include <iostream>
#include <string>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (this is the violation to detect)
//
// Seed (must appear in header): int g_counter = 0;   // NON-COMPLIANT header-level definition
//
// Also a non-inline function defined in the header (violates header-only-declarations guideline).
int g_counter = 0; // NON-COMPLIANT: non-const variable defined in header

void log_message(const std::string &msg) { // NON-COMPLIANT: function definition in header (non-inline)
    // simple deterministic logging (to stdout)
    std::cout << "[NC] " << msg << " counter=" << g_counter << '\n';
}
// ---------------------------------------------------------------------------

void increment_and_log() {
    // Use the header-defined function and variable as if they came from a header.
    ++g_counter;
    log_message("increment_and_log called");
}

int main() {
    // deterministic calls
    increment_and_log();
    increment_and_log();
    std::cout << "[NC] Final counter = " << g_counter << '\n';
    return 0;
}