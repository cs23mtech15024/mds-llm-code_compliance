// ------ Non-Compliant
// Seed: Non-compliant header: int max_connections = 10;   // Compliant header: extern int max_connections;
// Context: Adapted demo showing a header that wrongly defines a non-const global and a non-inline helper function.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?".
//   - cppreference: One Definition Rule / Definitions and ODR.
//   - PVS-Studio / static-analysis guidance on definitions in headers.
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int max_connections = 10;
int max_connections = 10; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline helper function defined in header
bool accept_new_connection(const std::string &peer) {
    static int current = 0;
    if (current < max_connections) {
        ++current;
        std::cout << "[NC] accept_new_connection: accepted " << peer
                  << " (current=" << current << " / max=" << max_connections << ")\n";
        return true;
    }
    std::cout << "[NC] accept_new_connection: rejected " << peer
              << " (current=" << current << " / max=" << max_connections << ")\n";
    return false;
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<std::string> peers = {"Alpha", "Bravo", "Charlie", "Delta", "Echo"};
    for (const auto &p : peers) {
        bool ok = accept_new_connection(p);
        (void)ok;
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    std::cout << "[NC] done\n";
    return 0;
}