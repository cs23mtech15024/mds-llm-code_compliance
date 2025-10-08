// ------ Compliant
// Seed: Non-compliant header: int buffer_size = 128;   // Compliant header: constexpr int buffer_size = 128;
// Context: Header defines a constexpr variable, which has internal linkage and is allowed under MISRA Rule 8-5-2.
// Provenance:
//  - cppreference: constexpr variables https://en.cppreference.com/w/cpp/language/constexpr
//  - StackOverflow: "Difference between const and constexpr in headers"
// Compliance: constexpr variables have internal linkage by default and are safe to define in headers.

#include <iostream>
#include <array>
#include <thread>
#include <chrono>

// ---------------- good_header.h (inlined here for demo) ----------------
// COMPLIANT: header defines constexpr global
//
// Seed: constexpr int buffer_size = 128;
constexpr int buffer_size = 128; // COMPLIANT: constexpr has internal linkage
// ----------------------------------------------------------------------

void collectTelemetry() {
    std::array<int, buffer_size> telemetry_data; // local array using constexpr size
    for (int i = 0; i < buffer_size; ++i)
        telemetry_data[i] = i * 2;
    std::cout << "[C] Collected " << buffer_size << " samples, first=" << telemetry_data[0] << '\n';
}

int main() {
    collectTelemetry();
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    std::cout << "[C] Done\n";
    return 0;
}