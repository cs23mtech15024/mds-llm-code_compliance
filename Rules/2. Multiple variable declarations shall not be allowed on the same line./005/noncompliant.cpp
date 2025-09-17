// ------ Non-Compliant
// Seed: Non-compliant: int a = 1, b = 2, c = 3;   // Compliant: int a = 1; int b = 2; int c = 3;
// Context: Calibration constants for DRDO sensor driver; deterministic calibration loop.
// Violation: Multiple variables declared in one statement (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:2‡MathWorks](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cmath>

// Non-compliant: three calibration constants declared in a single statement (seed)
void calibrate_nc(const std::vector<int>& samples, const std::string& logfile = "cal_nc.log") {
    // seed:
    int a = 1, b = 2, c = 3; // NON-COMPLIANT: multiple declarators in one declaration

    std::ofstream out(logfile, std::ios::app);
    if (!out) std::cerr << "[NC] Failed to open calibration log\n";

    int step = 0;
    for (int s : samples) {
        // deterministic "calibration" math using constants a,b,c
        double adjusted = (static_cast<double>(s) * a + b) / static_cast<double>(c);
        double corrected = std::sqrt(adjusted * adjusted + 0.01);

        if (out) out << "[NC] step=" << step << " raw=" << s
                    << " adj=" << std::fixed << std::setprecision(3) << adjusted
                    << " corr=" << corrected << '\n';

        ++step;
        // deterministic tiny delay to mimic processing latency
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    // final aggregate
    double mean = std::accumulate(samples.begin(), samples.end(), 0.0) / samples.size();
    std::cout << "[NC] constants: a=" << a << " b=" << b << " c=" << c
              << " mean_sample=" << std::fixed << std::setprecision(3) << mean << '\n';
}

int main() {
    // deterministic sample set
    std::vector<int> samples = {10, 12, 15, 11, 13, 14, 12, 13};
    calibrate_nc(samples);
    return 0;
}