// ------ Compliant
// Seed: Non-compliant header: static int connectionCount = 0;   // Compliant header: extern int connectionCount;
// Context: Header contains only declarations; definitions moved to implementation.
// Source: MISRA C++:2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
// Compliance: header area contains only declarations (extern and prototype); variable & function definitions are in implementation.

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int connectionCount;   // COMPLIANT header-level declaration
extern int connectionCount; // declaration only

// Function prototype only (no definition in header)
void report_connection(const std::string &peer);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int connectionCount = 0; // COMPLIANT: definition in implementation file

void report_connection(const std::string &peer) {
    std::cout << "[C] Connection established with " << peer
              << " (count=" << connectionCount << ")\n";
}

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
    std::cout << "[C] final connectionCount=" << connectionCount << '\n';
    return 0;
}