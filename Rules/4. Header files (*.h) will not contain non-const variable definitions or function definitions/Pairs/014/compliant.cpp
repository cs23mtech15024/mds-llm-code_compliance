// ------ Compliant
// Seed: Non-compliant header: char status_msg[] = "OK";   // Compliant header: extern char status_msg[];
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (extern guidance).
//  - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in the implementation area.

#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern char status_msg[];
extern char status_msg[]; // declaration only

// Function prototype only (no definition in header)
void print_status_and_update(int step);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
char status_msg[] = "OK"; // COMPLIANT: definition in implementation file

void print_status_and_update(int step) {
    std::cout << "[C] status=" << status_msg << " step=" << step << '\n';
    if (step % 2 == 0) {
        std::strncpy(status_msg, "EVEN", sizeof(status_msg));
    } else {
        std::strncpy(status_msg, "ODD", sizeof(status_msg));
    }
}

int main() {
    for (int i = 0; i < 4; ++i) {
        print_status_and_update(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    std::cout << "[C] final status_msg='" << status_msg << "'\n";
    return 0;
}