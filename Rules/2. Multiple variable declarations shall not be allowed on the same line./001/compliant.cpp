// ------ Compliant
// Seed: Non-compliant: int a, b;   // Compliant: int a; int b;
// Context: Simple telemetry aggregator counters in a DRDO logger.
// Violation: Multiple variable declarators on the same line (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <chrono>
#include <thread>
#include <iomanip>

// Simulate collecting telemetry samples and maintain two counters.
// Compliant: declare each counter on its own line (single init-declarator per declaration).
void telemetry_aggregate_C(const std::string &logfile = "telemetry_c.log") {
    int a = 0;
    int b = 0;
    // (compliant: split declarations so each init-declarator-list has exactly one declarator)

    std::vector<int> samples = {1, 2, 3, 4, 5, 6, 7, 8};
    // Simulate periodic ingestion of batches
    for (size_t batch = 0; batch < 3; ++batch) {
        for (auto s : samples) {
            a += s;              // first metric: sum of samples
            b += (s % 3 == 0);   // second metric: count of samples divisible by 3
        }
        // pretend to flush to disk
        std::ofstream out(logfile, std::ios::app);
        if (out) {
            out << "[C] Batch " << batch << " partial a=" << a << " b=" << b << '\n';
            out.close();
        } else {
            std::cerr << "[C] Failed to open log\n";
        }
        // emulate some delay typical in embedded logging (deterministic, small)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // compute simple stats
    double avg = static_cast<double>(a) / static_cast<double>(samples.size() * 3);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "[C] Final telemetry: a=" << a << " b=" << b << " avg=" << avg << '\n';
}

int main() {
    telemetry_aggregate_C();
    return 0;
}