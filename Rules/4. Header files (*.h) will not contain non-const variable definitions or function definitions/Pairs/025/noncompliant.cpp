// ------ Non-Compliant
// Seed: Non-compliant header: int g_counter = 0; double calibration = 1.5;  // Compliant header: extern int g_counter; extern double calibration;
// Context: Demonstrates multiple violations in a header-like region: two non-const global definitions and two non-inline function definitions.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?".
//  - cppreference: One Definition Rule / Definitions and ODR.
//  - PVS-Studio / static-analyzer guidance on avoiding variable definitions in headers.
// Violation: Header-like region contains multiple non-const variable definitions and multiple non-inline function definitions (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>
#include <cmath>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (multiple violations)
//
// Seed (must appear in header): int g_counter = 0; double calibration = 1.5;
int g_counter = 0;                  // NON-COMPLIANT: non-const global defined in header
double calibration = 1.5;           // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function definition in header
void record_sample_and_inc(int sample) {
    // simple deterministic processing and side-effect on header-defined globals
    double processed = sample * calibration;
    ++g_counter;
    std::cout << "[NC] record_sample_and_inc: sample=" << sample
              << " processed=" << processed << " g_counter=" << g_counter << '\n';
}

// NON-COMPLIANT: another non-inline function definition in header
double compute_average_and_adjust(const std::vector<int>& v) {
    double avg = v.empty() ? 0.0 : static_cast<double>(std::accumulate(v.begin(), v.end(), 0)) / v.size();
    double adjusted = avg * calibration;
    std::cout << "[NC] compute_average_and_adjust: avg=" << avg << " adjusted=" << adjusted << '\n';
    return adjusted;
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<int> samples = {10, 20, 30, 40};
    for (int s : samples) {
        record_sample_and_inc(s);
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    double result = compute_average_and_adjust(samples);
    std::cout << "[NC] final g_counter=" << g_counter << " final result=" << result << '\n';
    return 0;
}