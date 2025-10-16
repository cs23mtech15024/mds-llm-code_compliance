// ------ Compliant
// Seed: Non-compliant header: int access_mask = 0xFF;   // Compliant header: extern int access_mask;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//  - StackOverflow Q#1433204: guidance on extern vs definition for sharing globals.
//  - cppreference: One Definition Rule / Definitions and ODR (header-definition issues).
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in the implementation area.

#include <iostream>
#include <vector>
#include <cstdint>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int access_mask;
extern int access_mask; // declaration only

// Function prototype only (no definition in header)
bool check_permission(uint8_t flags);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int access_mask = 0xFF; // COMPLIANT: definition in implementation file

bool check_permission(uint8_t flags) {
    bool allowed = ((flags & static_cast<uint8_t>(access_mask & 0xFF)) != 0);
    std::cout << "[C] check_permission: flags=0x" << std::hex << int(flags)
              << " mask=0x" << (access_mask & 0xFF) << " allowed=" << std::dec << allowed << '\n';
    return allowed;
}

int main() {
    std::vector<uint8_t> requests = {0x01, 0x04, 0x80};
    int allowed_count = 0;
    for (auto f : requests) {
        if (check_permission(f)) ++allowed_count;
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    std::cout << "[C] allowed_count=" << allowed_count << " access_mask=0x" << std::hex << (access_mask & 0xFF) << std::dec << '\n';
    return 0;
}