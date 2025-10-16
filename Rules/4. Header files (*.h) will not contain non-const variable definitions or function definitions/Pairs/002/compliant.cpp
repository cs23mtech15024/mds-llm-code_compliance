// ------ Compliant
// Seed: Non-compliant header: bool ready = false;   // Compliant header: extern bool ready;
// Context: Header contains only declarations; definitions moved to implementation.
// Source: MISRA C++:2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
//         cppreference: One Definition Rule and header best practices.
// Compliance: header area contains only declarations (extern and prototype); variable and function definitions are in implementation area.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
// Seed (header declaration): extern bool ready;   // COMPLIANT header-level declaration
extern bool ready; // declaration

// Function prototype only (no definition in header)
void notify(const char *msg);
// ---------------------------------------------------------------------

// Implementation: definitions moved out of header area (compliant)
bool ready = false; // COMPLIANT: definition in implementation file

void notify(const char *msg) {
    std::cout << "[C] notify: " << msg << " ready=" << (ready ? "true" : "false") << '\n';
}

void initialize_system() {
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
    std::cout << "[C] final ready = " << (ready ? "true" : "false") << '\n';
    return 0;
}