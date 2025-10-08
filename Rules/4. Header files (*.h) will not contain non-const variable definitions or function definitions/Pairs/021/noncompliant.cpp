// ------ Non-Compliant
// Seed: Non-compliant header: int* ptr = nullptr;   // Compliant header: extern int* ptr;
// Context: Demonstration of a header that incorrectly defines a non-const pointer variable (violates header-only declarations).
// Provenance: StackOverflow discussion on 'extern' vs definitions in headers; cppreference ODR page; cppreference nullptr docs.
// Violation: Header contains a non-const pointer definition which can cause multiple-definition/ODR issues across translation units (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int* ptr = nullptr;
int* ptr = nullptr; // NON-COMPLIANT: non-const pointer variable defined in header

// NON-COMPLIANT: small helper function defined in header (non-inline)
void attach_and_report(int value) {
    // allocate an int and assign to header-defined pointer
    ptr = new int(value); // leaking for simplicity of demo; deterministic allocation
    std::cout << "[NC] attach_and_report: allocated value=" << *ptr << " ptr=" << static_cast<void*>(ptr) << '\n';
}
// ---------------------------------------------------------------------------

void demo() {
    attach_and_report(42);
    // use ptr deterministically
    if (ptr) {
        std::cout << "[NC] demo sees *ptr=" << *ptr << '\n';
        delete ptr; // free to avoid persistent leak across program (safe for single TU demo)
        ptr = nullptr;
    }
}

int main() {
    demo();
    // deterministic short pause
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    std::cout << "[NC] done\n";
    return 0;
}