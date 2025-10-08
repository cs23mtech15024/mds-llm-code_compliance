// ------ Non-Compliant
// Seed: Non-compliant header: double calibration = 1.234;   // Compliant header: extern double calibration;
// Context: Adapted demo showing a header that incorrectly defines a non-const global and a non-inline function.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?". 
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition. 
//   - PVS-Studio guidance: static-analysis notes on header definitions and best practices. 
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violation)
//
// Seed (must appear in header): double calibration = 1.234;
double calibration = 1.234; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function definition in header
double calibrate_sample(double raw) {
    // simple deterministic calibration example using header-defined global
    double adjusted = raw * calibration + std::sin(raw);
    std::cout << "[NC] calibrate_sample: raw=" << raw << " adjusted=" << adjusted << '\n';
    return adjusted;
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<double> samples = {0.1, 0.5, 1.0, 2.0};
    double sum = 0.0;
    for (double s : samples) {
        sum += calibrate_sample(s);
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
    std::cout << "[NC] sum=" << sum << " calibration=" << calibration << '\n';
    return 0;
}