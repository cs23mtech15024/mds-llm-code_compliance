// ------ Non-Compliant
// Seed: Non-compliant header: static int connectionCount = 0;   // Compliant header: extern int connectionCount;
// Context: Adapted demo showing a header that incorrectly defines non-const variables and non-inline functions.
// Source: MISRA C++:2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
// Violation: Header contains a non-const variable definition and a non-inline function definition (should be declarations only).

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (this is the violation to detect)
//
// Seed (must appear in header): static int connectionCount = 0;   // NON-COMPLIANT header-level definition
static int connectionCount = 0; // NON-COMPLIANT: non-const variable defined in header

// NON-COMPLIANT: non-inline function definition in header
void report_connection(const std::string &peer) {
    std::cout << "[NC] Connection established with " << peer
              << " (count=" << connectionCount << ")\n";
}
// ---------------------------------------------------------------------------

void open_connections_demo() {
    std::vector<std::string> peers = {"NodeA", "NodeB", "NodeC"};
    for (const auto &p : peers) {
        ++connectionCount;
        report_connection(p);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

int main() {
    open_connections_demo();
    std::cout << "[NC] final connectionCount=" << connectionCount << '\n';
    return 0;
}