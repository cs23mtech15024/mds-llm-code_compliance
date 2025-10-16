// ------ Non-Compliant
// Seed: Non-compliant: std::array<int,4> buf1, buf2;   // Compliant: std::array<int,4> buf1; std::array<int,4> buf2;
// Context: DMA buffer handling in a DRDO telemetry ingestion component.
// Violation: Declaring multiple variables in one declaration (MISRA C++:2008 Rule 8-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//          SEI CERT — DCL04-C: Do not declare more than one variable per declaration.  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <array>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <algorithm>

// Non-compliant: two std::array buffers declared on one line (seed)
void dma_ingest_NC(const std::string &logpath = "dma_nc.log") {
    // seed:
    std::array<int,4> buf1, buf2; // NON-COMPLIANT: multiple declarators in one declaration

    // deterministic fill for testing
    for (size_t i = 0; i < buf1.size(); ++i) {
        buf1[i] = static_cast<int>(i + 1);        // 1,2,3,4
        buf2[i] = static_cast<int>((i + 1) * 10); // 10,20,30,40
    }

    // compute simple checksums (sum of elements)
    int sum1 = std::accumulate(buf1.begin(), buf1.end(), 0);
    int sum2 = std::accumulate(buf2.begin(), buf2.end(), 0);

    // merge buffers into a small vector (interleave)
    std::vector<int> merged;
    merged.reserve(buf1.size() + buf2.size());
    for (size_t i = 0; i < buf1.size(); ++i) {
        merged.push_back(buf1[i]);
        merged.push_back(buf2[i]);
    }

    // deterministic logging
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(0);
    ss << "[NC] sum1=" << sum1 << " sum2=" << sum2 << " merged_size=" << merged.size() << '\n';
    std::cout << ss.str();

    std::ofstream out(logpath, std::ios::app);
    if (out) out << ss.str(); else std::cerr << "[NC] Failed to open log\n";

    // print merged contents in deterministic manner
    std::ostringstream mm;
    mm << "[NC] merged:";
    for (auto v : merged) mm << ' ' << v;
    mm << '\n';
    std::cout << mm.str();
    if (out) out << mm.str();

    // deterministic small sleep to mimic DMA latency
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
}

int main() {
    dma_ingest_NC();
    return 0;
}