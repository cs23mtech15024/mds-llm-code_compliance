// ------ Compliant
// Seed: Non-compliant header: int g_counter = 0;   // Compliant header: extern int g_counter;
// Context: Header now contains only declarations; definitions moved to implementation.
// Source: MISRA C++:2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
//         cppreference: One Definition Rule and header best practices.
// Compliance: header area contains only declarations (extern and prototype); variable & function definitions are in the .cpp implementation area.

#include <iostream>
#include <string>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int g_counter;   // COMPLIANT header-level declaration
extern int g_counter; // declaration only

// Function prototype only (no definition in header)
void log_message(const std::string &msg);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int g_counter = 0; // COMPLIANT: definition in implementation file (not in header)

void log_message(const std::string &msg) {
    // deterministic logging (to stdout)
    std::cout << "[C] " << msg << " counter=" << g_counter << '\n';
}

void increment_and_log() {
    ++g_counter;
    log_message("increment_and_log called");
}

int main() {
    // deterministic calls
    increment_and_log();
    increment_and_log();
    std::cout << "[C] Final counter = " << g_counter << '\n';
    return 0;
}