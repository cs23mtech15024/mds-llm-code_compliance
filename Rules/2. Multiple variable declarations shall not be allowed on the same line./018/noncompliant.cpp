// ------ Non-Compliant
// Seed: Non-compliant: std::map<int,int> m1, m2;   // Compliant: std::map<int,int> m1; std::map<int,int> m2;
// Context: Two mapping tables used by a DRDO telemetry translator (channel-to-code mappings).
// Violation: Declaring multiple variables of the same complex type in one declaration (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
// Note: SEI CERT DCL04-C also recommends one declaration per variable for clarity.  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Non-compliant: two maps declared on one line (seed)
void mapping_demo_NC(const std::string &logpath = "map_nc.log") {
    // seed:
    std::map<int,int> m1, m2; // NON-COMPLIANT: multiple declarators in one declaration

    // prepare deterministic mappings
    for (int i = 0; i < 8; ++i) {
        m1[i] = i * 10;                 // channel -> code
        m2[i + 100] = (i + 100) * 2;    // alternate channel namespace
    }

    // deterministic lookup & merge behavior: create a merged vector of pairs
    std::vector<std::pair<int,int>> merged;
    merged.reserve(m1.size() + m2.size());
    for (const auto &kv : m1) merged.emplace_back(kv.first, kv.second);
    for (const auto &kv : m2) merged.emplace_back(kv.first, kv.second);

    // log a few entries
    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[NC] Failed to open log\n";

    for (size_t i = 0; i < merged.size(); ++i) {
        if (i % 3 == 0) {
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(0);
            ss << "[NC] entry[" << i << "] key=" << merged[i].first << " val=" << merged[i].second << '\n';
            std::cout << ss.str();
            if (out) out << ss.str();
        }
        // deterministic delay to mimic I/O
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    // small deterministic summary
    std::cout << "[NC] sizes m1=" << m1.size() << " m2=" << m2.size() << " merged=" << merged.size() << '\n';
    if (out) { out << "[NC] sizes m1=" << m1.size() << " m2=" << m2.size() << " merged=" << merged.size() << '\n'; out.close(); }
}

int main() {
    mapping_demo_NC();
    return 0;
}