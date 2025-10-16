// ------ Compliant
// Seed: Non-compliant header: int S::x = 5;   // Compliant: move definition to implementation
// Context: Header-like region contains only the class declaration; the static member definition and function implementations are in the implementation area.
// Provenance:
//  - cppreference: static data members and where they are defined. https://en.cppreference.com/w/cpp/language/static
//  - StackOverflow: common Q/A about "defining static member in header causing multiple definitions"
// Compliance: Header-like area has only the declaration `static int x;`; `int S::x = 5;` has been moved to the implementation section.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): struct S { static int x; };
struct S {
    static int x; // declaration only
};

// Prototype only — no function body in header-like region
void report_S();
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header-like area (compliant)
int S::x = 5; // COMPLIANT: static member definition in implementation file

void report_S() {
    std::cout << "[C] S::x = " << S::x << '\n';
}

void increment_and_report() {
    ++S::x;
    report_S();
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
}

int main() {
    report_S();
    increment_and_report();
    increment_and_report();
    std::cout << "[C] final S::x = " << S::x << '\n';
    return 0;
}