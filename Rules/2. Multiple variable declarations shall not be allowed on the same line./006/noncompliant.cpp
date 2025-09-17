// ------ Non-Compliant
// Seed: Non-compliant: auto x = 1, y = 2;   // Compliant: auto x = 1; auto y = 2;
// Context: Deterministic test-harness for DRDO sensor processing counters.
// Violation: Multiple variables declared in a single init-declarator-list (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:2‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <thread>
#include <chrono>

// Small deterministic simulator: count events above two thresholds using type-deduction.
// NON-COMPLIANT: two variables declared with a single 'auto' declaration (seed).
void counter_simulator_NC(const std::vector<int>& samples, const std::string &logpath = "counter_nc.log") {
    // seed:
    auto x = 1, y = 2; // NON-COMPLIANT: multiple declarators in one declaration

    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[NC] Failed to open log\n";

    for (size_t idx = 0; idx < samples.size(); ++idx) {
        int s = samples[idx];
        // increment counters deterministically using thresholds
        if (s > 10) ++x;      // first counter: events >10
        if (s > 20) ++y;      // second counter: events >20

        if (idx % 4 == 0 && out) {
            out << "[NC] idx=" << idx << " sample=" << s << " x=" << x << " y=" << y << '\n';
        }
        // small deterministic delay
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }

    double ratio = (samples.empty()) ? 0.0 : static_cast<double>(y) / static_cast<double>(x + 1);
    std::cout << std::fixed << std::setprecision(3)
              << "[NC] final x=" << x << " y=" << y << " ratio=" << ratio << '\n';
}

int main() {
    // deterministic sample stream
    std::vector<int> samples = {5, 12, 7, 25, 18, 30, 2, 11, 21, 19, 22, 9};
    counter_simulator_NC(samples);
    return 0;
}