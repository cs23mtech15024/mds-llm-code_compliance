// ------ Non-Compliant
// Seed: Non-compliant header: int buffer_size = 128;   // Compliant header: constexpr int buffer_size = 128;
// Context: Header defines a non-const global variable, violating MISRA C++ Rule 8-5-2.
// Provenance:
//  - cppreference: constexpr variables https://en.cppreference.com/w/cpp/language/constexpr
//  - StackOverflow: "Difference between const and constexpr in headers"
// Violation: The header defines a non-const global variable (`int buffer_size = 128;`), which can lead to ODR violations.

#include <iostream>
#include <array>
#include <thread>
#include <chrono>

// ---------------- bad_header.h (inlined here for demo) ----------------
// NON-COMPLIANT: header defines non-const global
//
// Seed: int buffer_size = 128;
int buffer_size = 128; // NON-COMPLIANT: definition in header (ODR violation risk)
// ----------------------------------------------------------------------

void collectTelemetry() {
    std::array<int, 128> telemetry_data; // local array using the size
    for (int i = 0; i < buffer_size; ++i)
        telemetry_data[i] = i * 2;
    std::cout << "[NC] Collected " << buffer_size << " samples, first=" << telemetry_data[0] << '\n';
}

int main() {
    collectTelemetry();
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    std::cout << "[NC] Done\n";
    return 0;
}