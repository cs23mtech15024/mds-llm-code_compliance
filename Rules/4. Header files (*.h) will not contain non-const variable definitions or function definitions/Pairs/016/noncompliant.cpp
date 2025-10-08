// ------ Non-Compliant
// Seed: Non-compliant header: int access_mask = 0xFF;   // Compliant header: extern int access_mask;
// Context: Demonstration of a header that incorrectly defines a non-const global access mask and a non-inline helper.
// Provenance:
//  - StackOverflow Q#1433204: guidance on extern vs definition for sharing globals.
//  - cppreference: One Definition Rule / Definitions and ODR (header-definition issues).
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <cstdint>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int access_mask = 0xFF;
int access_mask = 0xFF; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function defined in header (should be prototype only)
bool check_permission(uint8_t flags) {
    // simple deterministic check using header-defined access_mask
    bool allowed = ((flags & static_cast<uint8_t>(access_mask & 0xFF)) != 0);
    std::cout << "[NC] check_permission: flags=0x" << std::hex << int(flags)
              << " mask=0x" << (access_mask & 0xFF) << " allowed=" << std::dec << allowed << '\n';
    return allowed;
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<uint8_t> requests = {0x01, 0x04, 0x80};
    int allowed_count = 0;
    for (auto f : requests) {
        if (check_permission(f)) ++allowed_count;
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    std::cout << "[NC] allowed_count=" << allowed_count << " access_mask=0x" << std::hex << (access_mask & 0xFF) << std::dec << '\n';
    return 0;
}