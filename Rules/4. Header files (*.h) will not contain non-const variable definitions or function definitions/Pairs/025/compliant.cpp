// ------ Compliant
// Seed: Non-compliant header: int g_counter = 0; double calibration = 1.5;  // Compliant header: extern int g_counter; extern double calibration;
// Context: Header-like region contains only declarations; the two globals and two functions are defined in the implementation area.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?".
//  - cppreference: One Definition Rule / Definitions and ODR.
//  - PVS-Studio / static-analyzer guidance on avoiding variable definitions in headers.
// Compliance: Header-like region now holds only extern declarations and prototypes; definitions moved to the implementation section.

#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>
#include <cmath>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int g_counter; extern double calibration;
extern int g_counter;                 // declaration only
extern double calibration;            // declaration only

// Function prototypes only (no definitions in header)
void record_sample_and_inc(int sample);
double compute_average_and_adjust(const std::vector<int>& v);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header-like area (compliant)
int g_counter = 0;                // COMPLIANT: single definition in implementation
double calibration = 1.5;         // COMPLIANT: single definition in implementation

void record_sample_and_inc(int sample) {
    double processed = sample * calibration;
    ++g_counter;
    std::cout << "[C] record_sample_and_inc: sample=" << sample
              << " processed=" << processed << " g_counter=" << g_counter << '\n';
}

double compute_average_and_adjust(const std::vector<int>& v) {
    double avg = v.empty() ? 0.0 : static_cast<double>(std::accumulate(v.begin(), v.end(), 0)) / v.size();
    double adjusted = avg * calibration;
    std::cout << "[C] compute_average_and_adjust: avg=" << avg << " adjusted=" << adjusted << '\n';
    return adjusted;
}

int main() {
    std::vector<int> samples = {10, 20, 30, 40};
    for (int s : samples) {
        record_sample_and_inc(s);
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    double result = compute_average_and_adjust(samples);
    std::cout << "[C] final g_counter=" << g_counter << " final result=" << result << '\n';
    return 0;
}