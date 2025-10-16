// ------ Compliant
// Seed: Non-compliant header: int* ptr = nullptr;   // Compliant header: extern int* ptr;
// Context: Header contains only declarations; pointer definition moved into implementation.
// Provenance: StackOverflow discussion on 'extern' vs definitions in headers; cppreference ODR page; cppreference nullptr docs.
// Compliance: Header-like region contains only declarations (extern and prototype); definition moved to implementation area.

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int* ptr;
extern int* ptr; // declaration only

// Function prototype only (no definition in header)
void attach_and_report(int value);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int* ptr = nullptr; // COMPLIANT: pointer definition in implementation file

void attach_and_report(int value) {
    ptr = new int(value); // deterministic allocation for demo
    std::cout << "[C] attach_and_report: allocated value=" << *ptr << " ptr=" << static_cast<void*>(ptr) << '\n';
}

void demo() {
    attach_and_report(42);
    if (ptr) {
        std::cout << "[C] demo sees *ptr=" << *ptr << '\n';
        delete ptr;
        ptr = nullptr;
    }
}

int main() {
    demo();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    std::cout << "[C] done\n";
    return 0;
}