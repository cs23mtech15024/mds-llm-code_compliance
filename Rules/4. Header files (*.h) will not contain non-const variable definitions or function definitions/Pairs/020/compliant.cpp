// ------ Compliant
// Seed: Non-compliant header: int config_version = 1;   // Compliant header: extern int config_version;
// Context: Header contains only declarations; definitions moved to implementation.
// Provenance:
//   - StackOverflow Q#1433204: “How do I use extern to share variables between source files?”
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
//   - MISRA / PVS-Studio documentation on header definition violations.
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in implementation.

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int config_version;
extern int config_version; // declaration only

// Function prototype only (no definition in header)
void update_configuration(const std::string &component, int version);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int config_version = 1; // COMPLIANT: definition in implementation file

void update_configuration(const std::string &component, int version) {
    config_version = version;
    std::cout << "[C] update_configuration: " << component 
              << " set version=" << config_version << '\n';
}

int main() {
    update_configuration("RadarModule", 2);
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    update_configuration("CommModule", 3);
    std::cout << "[C] final config_version=" << config_version << '\n';
    return 0;
}