// ------ Compliant
// Seed: Non-compliant header: int max_connections = 10;   // Compliant header: extern int max_connections;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?".
//   - cppreference: One Definition Rule / Definitions and ODR.
//   - PVS-Studio / static-analysis guidance on definitions in headers.
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in implementation.

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int max_connections;
extern int max_connections; // declaration only

// Function prototype only (no definition in header)
bool accept_new_connection(const std::string &peer);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int max_connections = 10; // COMPLIANT: definition in implementation file

bool accept_new_connection(const std::string &peer) {
    static int current = 0;
    if (current < max_connections) {
        ++current;
        std::cout << "[C] accept_new_connection: accepted " << peer
                  << " (current=" << current << " / max=" << max_connections << ")\n";
        return true;
    }
    std::cout << "[C] accept_new_connection: rejected " << peer
              << " (current=" << current << " / max=" << max_connections << ")\n";
    return false;
}

int main() {
    std::vector<std::string> peers = {"Alpha", "Bravo", "Charlie", "Delta", "Echo"};
    for (const auto &p : peers) {
        bool ok = accept_new_connection(p);
        (void)ok;
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    std::cout << "[C] done\n";
    return 0;
}