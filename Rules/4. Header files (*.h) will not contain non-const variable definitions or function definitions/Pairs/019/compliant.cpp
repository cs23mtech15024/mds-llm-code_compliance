// ------ Compliant
// Seed: Non-compliant header: bool debug_flag = false;   // Compliant header: extern bool debug_flag;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//   - StackOverflow Q#1433204: “How do I use extern to share variables between source files?”
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
//   - PVS-Studio / static analyzer guidance: “Avoid variable definitions in headers”.
// Compliance: Header-like region contains only declarations (extern and prototype); definitions moved to implementation section.

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern bool debug_flag;
extern bool debug_flag; // declaration only

// Function prototype only (no definition in header)
void log_message(const std::string &msg);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
bool debug_flag = false; // COMPLIANT: definition in implementation file

void log_message(const std::string &msg) {
    if (debug_flag) {
        std::cout << "[C-DEBUG] " << msg << '\n';
    }
    else {
        std::cout << "[C] (quiet mode) " << msg << '\n';
    }
}

int main() {
    log_message("Starting diagnostics...");
    debug_flag = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    log_message("Diagnostics completed.");
    return 0;
}