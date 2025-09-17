// ------ Non-Compliant
// Seed: Non-compliant: uint32_t mask = 0u, flags = 0u;   // Compliant: uint32_t mask = 0u; uint32_t flags = 0u;
// Context: Access-control mask and flags for a DRDO security module — simulate applying mask/flags to a small access table.
// Violation: Declaring multiple variables in the same declaration (MISRA C++:2008 Rule 8-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//          SEI CERT — DCL04-C (do not declare more than one variable per declaration).  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Non-compliant: mask and flags declared together (seed)
void access_apply_NC(const std::string &logpath = "access_nc.log") {
    // seed:
    uint32_t mask = 0u, flags = 0u; // NON-COMPLIANT: multiple declarators in one declaration

    // deterministic "access table" entries: each entry is a 32-bit capability word
    std::vector<uint32_t> entries = {
        0x00000001u, 0x00000003u, 0x00000007u, 0x0000000Fu,
        0x00000010u, 0x00000020u, 0x000000FFu, 0x0000FF00u
    };

    // set a deterministic mask and flags (simulate reading from config)
    mask = 0x000000FFu;   // keep lower byte
    flags = 0x00000001u;  // check LSB permission

    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[NC] Failed to open log\n";

    size_t allowed = 0;
    for (size_t i = 0; i < entries.size(); ++i) {
        uint32_t e = entries[i];
        uint32_t filtered = e & mask;
        bool ok = (filtered & flags) != 0u;

        std::ostringstream ss;
        ss << std::hex << std::showbase << std::setw(8) << std::setfill('0');
        ss << "[NC] entry[" << i << "] raw=" << e << " filtered=" << filtered << " permitted=" << std::boolalpha << ok << '\n';

        std::cout << ss.str();
        if (out) out << ss.str();

        if (ok) ++allowed;

        // deterministic tiny delay to mimic processing
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    std::ostringstream fin;
    fin << std::dec << "[NC] allowed=" << allowed << " total=" << entries.size() << '\n';
    std::cout << fin.str();
    if (out) { out << fin.str(); out.close(); }
}

int main() {
    access_apply_NC();
    return 0;
}