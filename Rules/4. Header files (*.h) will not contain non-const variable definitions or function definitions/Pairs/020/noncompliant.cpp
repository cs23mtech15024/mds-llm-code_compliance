// ------ Non-Compliant
// Seed: Non-compliant header: int config_version = 1;   // Compliant header: extern int config_version;
// Context: Header incorrectly defines a mutable configuration version variable and a function definition.
// Provenance:
//   - StackOverflow Q#1433204: “How do I use extern to share variables between source files?”
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
//   - MISRA / PVS-Studio documentation on header definition violations.
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int config_version = 1;
int config_version = 1; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function defined in header
void update_configuration(const std::string &component, int version) {
    config_version = version;
    std::cout << "[NC] update_configuration: " << component 
              << " set version=" << config_version << '\n';
}
// ---------------------------------------------------------------------------

int main() {
    update_configuration("RadarModule", 2);
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    update_configuration("CommModule", 3);
    std::cout << "[NC] final config_version=" << config_version << '\n';
    return 0;
}