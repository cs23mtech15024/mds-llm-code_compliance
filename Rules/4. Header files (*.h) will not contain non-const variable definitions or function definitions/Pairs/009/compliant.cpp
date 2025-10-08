// ------ Compliant
// Seed: Non-compliant header: double calibration = 1.234;   // Compliant header: extern double calibration;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?". 
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition. 
//   - PVS-Studio guidance: static-analysis notes on header definitions and best practices. 
// Compliance: Header region contains only declarations (extern and prototype); global & function definitions are in the implementation area.

#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern double calibration;
extern double calibration; // declaration only

// Function prototype only (no definition in header)
double calibrate_sample(double raw);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
double calibration = 1.234; // COMPLIANT: definition in implementation file

double calibrate_sample(double raw) {
    double adjusted = raw * calibration + std::sin(raw);
    std::cout << "[C] calibrate_sample: raw=" << raw << " adjusted=" << adjusted << '\n';
    return adjusted;
}

int main() {
    std::vector<double> samples = {0.1, 0.5, 1.0, 2.0};
    double sum = 0.0;
    for (double s : samples) {
        sum += calibrate_sample(s);
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
    std::cout << "[C] sum=" << sum << " calibration=" << calibration << '\n';
    return 0;
}