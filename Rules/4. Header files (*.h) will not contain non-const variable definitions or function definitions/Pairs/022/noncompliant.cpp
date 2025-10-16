// ------ Non-Compliant
// Seed: Non-compliant header: int S::x = 5;   // Compliant: move definition to implementation
// Context: Demonstration of a header that defines a class static data member in the header (violates header-only-declarations).
// Provenance:
//  - cppreference: static data members and where they are defined. https://en.cppreference.com/w/cpp/language/static
//  - StackOverflow: common Q/A about "defining static member in header causing multiple definitions"
// Violation: Header-like region contains an out-of-class definition of a static data member `int S::x = 5;` (non-const), which should be in an implementation file; also shows a non-inline function defined in header-like region.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains an out-of-class definition of a static member (violates Rule 8-5-2)
//
// Seed (must appear in header): int S::x = 5;
struct S {
    static int x; // declaration only inside class (allowed)
};

// OUT-OF-CLASS DEFINITION IN HEADER — NON-COMPLIANT
int S::x = 5; // NON-COMPLIANT: definition of static member in header (should be in a single .cpp)

// NON-COMPLIANT: non-inline function definition in header-like region
void report_S() {
    std::cout << "[NC] S::x = " << S::x << '\n';
}
// ---------------------------------------------------------------------------

void increment_and_report() {
    ++S::x;
    report_S();
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
}

int main() {
    report_S();
    increment_and_report();
    increment_and_report();
    std::cout << "[NC] final S::x = " << S::x << '\n';
    return 0;
}