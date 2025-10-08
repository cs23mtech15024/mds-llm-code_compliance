// ------ Compliant
// Seed: Non-compliant header: int session_id = 0;   // Compliant header: extern int session_id;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?". 
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
//   - PVS-Studio / static analyzer guidance: warnings about definitions in headers and header best practices.
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in the implementation area.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int session_id;
extern int session_id; // declaration only

// Function prototype only (no definition in header)
void start_session_for(const std::string &who);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int session_id = 0; // COMPLIANT: definition in implementation file

void start_session_for(const std::string &who) {
    ++session_id;
    std::cout << "[C] start_session_for: " << who << " session=" << session_id << '\n';
}

void run_workflow() {
    start_session_for("OperatorA");
    std::this_thread::sleep_for(std::chrono::milliseconds(4));
    start_session_for("OperatorB");
}

int main() {
    run_workflow();
    std::cout << "[C] final session_id=" << session_id << '\n';
    return 0;
}