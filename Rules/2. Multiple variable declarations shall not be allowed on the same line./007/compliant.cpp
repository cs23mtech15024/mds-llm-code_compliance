// ------ Compliant
// Seed: Non-compliant: std::vector<int> a, b;   // Compliant: std::vector<int> a; std::vector<int> b;
// Context: Packet buffers for two channels in a DRDO communication subsystem.
// Violation: Declaring multiple variables on the same line (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <thread>
#include <chrono>
#include <iomanip>

// Compliant example: each vector declared on its own line
void buffer_process_C(const std::string &logpath = "buffers_c.log") {
    std::vector<int> a;
    std::vector<int> b;
    // (compliant: split declarations so each init-declarator-list has a single declarator)

    // Prepare deterministic data for two channels
    for (int i = 1; i <= 16; ++i) {
        if (i % 2 == 0) a.push_back(i); else b.push_back(i);
    }

    // Simulate processing: compute per-buffer sums and merge small window
    int sum_a = std::accumulate(a.begin(), a.end(), 0);
    int sum_b = std::accumulate(b.begin(), b.end(), 0);
    std::vector<int> merged;
    merged.reserve(a.size() + b.size());
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(merged));

    // Log results
    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[C] Failed to open log\n";
    if (out) {
        out << "[C] sum_a=" << sum_a << " sum_b=" << sum_b << " merged_size=" << merged.size() << '\n';
    }

    // Print summary (deterministic)
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "[C] a.size=" << a.size() << " b.size=" << b.size()
              << " sum_a=" << sum_a << " sum_b=" << sum_b << '\n';

    // emulate deterministic processing delay
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main() {
    buffer_process_C();
    return 0;
}