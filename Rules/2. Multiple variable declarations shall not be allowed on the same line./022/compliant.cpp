// ------ Compliant
// Seed: Non-compliant: struct Reg { unsigned flags:3, mode:5; };   // Compliant: struct Reg { unsigned flags:3; unsigned mode:5; };
// Context: Hardware register bit-field declarations in an embedded DRDO module.
// Violation: Declaring multiple bit-field members in one member-declarator-list (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:5‡es.mathworks.com](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
// Note: Bit-field layout is implementation-defined; prefer clear, single-member declarations for readability/maintainability.  [oai_citation:6‡SEI Wiki](https://wiki.sei.cmu.edu/confluence/display/c/EXP11-C.%2BDo%2Bnot%2Bmake%2Bassumptions%2Bregarding%2Bthe%2Blayout%2Bof%2Bstructures%2Bwith%2Bbit-fields?utm_source=chatgpt.com)

#include <cstdint>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>

// Compliant: declare each bit-field member on its own line (single member-declarator per declaration)
struct Reg {
    unsigned flags:3;
    unsigned mode:5;
    Reg() : flags(0), mode(0) {}
};

// deterministic routine that manipulates registers (identical logic to NC)
void reg_demo_C(const std::string &logpath = "regbits_c.log") {
    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[C] Failed to open log\n";

    // create deterministic set of operations (values fit into bit-fields)
    std::vector<unsigned> ops = {0u, 1u, 3u, 7u, 4u, 2u};

    for (size_t i = 0; i < ops.size(); ++i) {
        Reg r;
        // assign flag (low 3 bits) and mode (next 5 bits) deterministically from ops
        r.flags = ops[i] & 0x7u;              // 3-bit value
        r.mode  = (ops[i] * 2u) & 0x1Fu;      // 5-bit value

        // combine into a single word for logging (layout implementation-defined; for demo we pack as (mode<<3)|flags)
        uint32_t packed = (static_cast<uint32_t>(r.mode) << 3) | static_cast<uint32_t>(r.flags);

        std::ostringstream ss;
        ss << std::hex << std::showbase << std::setw(2) << std::setfill('0');
        ss << "[C] step=" << i << " flags=" << std::dec << r.flags
           << " mode=" << std::dec << r.mode << " packed=0x" << std::hex << packed << '\n';

        std::cout << ss.str();
        if (out) out << ss.str();

        // deterministic small pause
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    if (out) out.close();
}

int main() {
    reg_demo_C();
    return 0;
}