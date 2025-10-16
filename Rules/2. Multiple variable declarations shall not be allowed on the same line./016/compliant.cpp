// ------ Compliant
// Seed: Non-compliant: float f1 = 1.0f, f2 = 2.0f;   // Compliant: float f1 = 1.0f; float f2 = 2.0f;
// Context: Two floating-point calibration factors used in a DRDO signal normalization routine.
// Violation: Declaring multiple variables in one declaration (MISRA C++:2008 Rule 8-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:4‡MathWorks](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//          SEI CERT — DCL04-C (do not declare more than one variable per declaration).  [oai_citation:5‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cmath>
#include <sstream>

// Compliant: each calibration factor declared on its own line (single declarator per declaration)
void normalize_samples_C(const std::vector<float>& samples, const std::string &logpath = "norm_c.log") {
    float f1 = 1.0f;
    float f2 = 2.0f;
    // (compliant: split declarations so each init-declarator-list has one declarator)

    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[C] Failed to open log\n";

    std::vector<float> out1;
    std::vector<float> out2;
    out1.reserve(samples.size());
    out2.reserve(samples.size());

    for (size_t i = 0; i < samples.size(); ++i) {
        float s = samples[i];
        // apply two calibration factors in parallel (deterministic math)
        float r1 = s * f1 + 0.5f;
        float r2 = std::sqrt(std::fabs(s)) * f2;

        out1.push_back(r1);
        out2.push_back(r2);

        if (i % 3 == 0) {
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(3);
            ss << "[C] idx=" << i << " s=" << s << " r1=" << r1 << " r2=" << r2 << '\n';
            std::cout << ss.str();
            if (out) out << ss.str();
        }
        // tiny deterministic delay
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }

    // compute simple aggregates
    double sum1 = std::accumulate(out1.begin(), out1.end(), 0.0);
    double sum2 = std::accumulate(out2.begin(), out2.end(), 0.0);

    std::ostringstream fin;
    fin << std::fixed << std::setprecision(3);
    fin << "[C] final sum1=" << sum1 << " sum2=" << sum2 << " samples=" << samples.size() << '\n';
    std::cout << fin.str();
    if (out) { out << fin.str(); out.close(); }
}

int main() {
    // deterministic sample set
    std::vector<float> samples = {0.0f, 1.0f, 4.0f, 9.0f, 16.0f, 25.0f, 36.0f, 49.0f};
    normalize_samples_C(samples);
    return 0;
}