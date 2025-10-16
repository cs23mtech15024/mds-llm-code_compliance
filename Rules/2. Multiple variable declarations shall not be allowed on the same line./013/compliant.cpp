// ------ Compliant
// Seed: Non-compliant: unsigned u1 = 0u, u2 = 1u;   // Compliant: unsigned u1 = 0u; unsigned u2 = 1u;
// Context: Two unsigned counters used for packet/telemetry channel indexing in a DRDO data-collector module.
// Violation: Declaring multiple variables in a single declaration (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <chrono>

// Compliant: each counter declared on its own line (single init-declarator per declaration)
void channel_counters_C(const std::string &logpath = "chan_c.log") {
    unsigned u1 = 0u;
    unsigned u2 = 1u;
    // (compliant: split declarations so each init-declarator-list has one declarator)

    std::vector<unsigned> packet_sizes = {64u, 128u, 256u, 64u, 128u, 512u, 64u, 256u};
    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[C] Failed to open log\n";

    for (size_t i = 0; i < packet_sizes.size(); ++i) {
        unsigned sz = packet_sizes[i];
        // deterministic update policy:
        u1 += (sz / 64u);          // first counter increments in 64-byte units
        u2 += (i % 2 == 0) ? 1u : 0u; // second counter increments every other packet

        if (i % 3 == 0 && out) {
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(0);
            ss << "[C] idx=" << i << " sz=" << sz << " u1=" << u1 << " u2=" << u2 << '\n';
            out << ss.str();
            std::cout << ss.str();
        }
        // small, deterministic delay to emulate processing
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    std::ostringstream fin;
    fin << std::fixed << std::setprecision(0);
    fin << "[C] final u1=" << u1 << " u2=" << u2 << '\n';
    std::cout << fin.str();
    if (out) { out << fin.str(); out.close(); }
}

int main() {
    channel_counters_C();
    return 0;
}