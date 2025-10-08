// ------ Compliant
// Seed: Non-compliant: int i = 0, j = 0, k = 0;   // Compliant: int i = 0; int j = 0; int k = 0;
// Context: Loop counters across three parallel processing channels in a DRDO signal-processing routine.
// Violation: Declaring multiple variables in a single declaration (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Simulate three parallel channels processing stream windows.
// COMPLIANT: counters declared on separate lines (single declarator per declaration).
void process_channels_C(const std::vector<int>& data, const std::string &logpath = "chan_c.log") {
    int i = 0;
    int j = 0;
    int k = 0;
    // (compliant: split the multi-declaration so each init-declarator-list has one declarator)

    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[C] Failed to open log\n";

    const size_t window = 4;
    for (size_t w = 0; w + window <= data.size(); w += window) {
        int sum0 = 0;
        int sum1 = 0;
        int sum2 = 0;
        for (size_t t = 0; t < window; ++t) {
            int val = data[w + t];
            // deterministic distribution to channels
            if (t % 3 == 0) { sum0 += val; ++i; }
            else if (t % 3 == 1) { sum1 += val; ++j; }
            else { sum2 += val; ++k; }
        }
        if (out) out << "[C] window=" << w/window << " s0=" << sum0 << " s1=" << sum1 << " s2=" << sum2 << '\n';
        // small deterministic processing delay
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    double avg_events = static_cast<double>(i + j + k) / 3.0;
    std::cout << std::fixed << std::setprecision(2)
              << "[C] counts i=" << i << " j=" << j << " k=" << k << " avg=" << avg_events << '\n';
}

int main() {
    // deterministic sample stream
    std::vector<int> data(24);
    for (size_t idx = 0; idx < data.size(); ++idx) data[idx] = static_cast<int>(idx + 1);

    process_channels_C(data);
    return 0;
}