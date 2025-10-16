// ------ Compliant
// Seed: Non-compliant: volatile uint32_t regA = 0u, regB = 0u;   // Compliant: volatile uint32_t regA = 0u; volatile uint32_t regB = 0u;
// Context: Simulated memory-mapped register handling for DRDO embedded control.
// Violation: Declaring multiple volatile register variables in one declaration (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:5‡MathWorks](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//         SEI CERT — DCL04-C (do not declare more than one variable per declaration).  [oai_citation:6‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <cstdint>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include <algorithm>

// Compliant: each volatile register declared on its own line (single declarator per declaration)
void reg_handler_C(const std::string &logpath = "reg_c.log") {
    volatile uint32_t regA = 0u;
    volatile uint32_t regB = 0u;
    // (compliant: split declarations so each init-declarator-list has a single declarator)

    // deterministic sequence of simulated writes and masks
    std::vector<uint32_t> ops = {0x00000001u, 0x00000010u, 0x00000100u, 0xFFFFFFFFu, 0x0000FF00u};
    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[C] Failed to open log\n";

    for (size_t i = 0; i < ops.size(); ++i) {
        uint32_t v = ops[i];
        // deterministic policy: alternate writes and masked writes
        if (i % 2 == 0) {
            regA = v;
            regB = (regB & 0xFFFFFF00u) | (v & 0xFFu);
        } else {
            regB = v;
            regA = (regA & 0xFFFF00FFu) | ((v & 0xFFu) << 8);
        }

        std::ostringstream ss;
        ss << std::hex << std::showbase << std::setw(8) << std::setfill('0');
        ss << "[C] step=" << i << " op=" << v << " regA=" << static_cast<uint32_t>(regA)
           << " regB=" << static_cast<uint32_t>(regB) << '\n';
        std::cout << ss.str();
        if (out) out << ss.str();

        // deterministic pause
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    // final deterministic summary
    std::ostringstream fin;
    fin << std::dec << "[C] final regA=" << static_cast<uint32_t>(regA)
        << " regB=" << static_cast<uint32_t>(regB) << '\n';
    std::cout << fin.str();
    if (out) { out << fin.str(); out.close(); }
}

int main() {
    reg_handler_C();
    return 0;
}