// ------ Non-Compliant
// Seed: Non-compliant: unsigned _checksum = 0u;   // Compliant: unsigned checksum = 0u;
// Context: Message integrity helper used in a DRDO telemetry link — deterministic checksum computation.
// Violation: identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:6‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          cppreference — identifier rules (C++ standard).  [oai_citation:7‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          PVS-Studio: identifiers that start with '__' or '_[A-Z]' are reserved.  [oai_citation:8‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          StackOverflow: rules about underscores in C++ identifiers.  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          SEI / CERT guidance on reserved identifiers.  [oai_citation:10‡wiki.sei.cmu.edu](https://wiki.sei.cmu.edu/confluence/display/cplusplus/DCL51-CPP.%2BDo%2Bnot%2Bdeclare%2Bor%2Bdefine%2Ba%2Breserved%2Bidentifier?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <chrono>
#include <thread>
#include <algorithm>

// Non-compliant: global/static identifier starts with underscore (seed)
static unsigned _checksum = 0u; // NON-COMPLIANT: leading underscore in identifier (seed)

// simple deterministic packet structure
struct Packet {
    uint16_t id;
    std::vector<uint8_t> payload;
};

namespace drdo {
    // deterministic checksum transform (toy, non-cryptographic)
    inline unsigned compute_raw(const Packet &p) {
        unsigned s = 0u;
        for (uint8_t b : p.payload) {
            s = (s + static_cast<unsigned>(b) + (p.id & 0xFFu)) & 0xFFFFu;
            s ^= (s >> 8);
        }
        return s & 0xFFFFu;
    }
}

void tag_and_log_NC(std::vector<Packet> inbox) {
    std::ofstream log("checksum_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < inbox.size(); ++i) {
        Packet &p = inbox[i];
        // deterministic running checksum usage
        _checksum = (drdo::compute_raw(p) + _checksum) & 0xFFFFu;

        // append 2-byte checksum to payload deterministically
        p.payload.push_back(static_cast<uint8_t>(_checksum & 0xFFu));
        p.payload.push_back(static_cast<uint8_t>((_checksum >> 8) & 0xFFu));

        log << "[NC] pktIdx=" << i << " id=" << p.id << " chk=0x" << std::hex << _checksum << std::dec << '\n';
        std::cout << "[NC] processed pkt " << i << " chk=0x" << std::hex << _checksum << std::dec << '\n';

        // deterministic pause to emulate processing
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }

    log.close();
}

int main() {
    // deterministic synthetic packets
    std::vector<Packet> inbox;
    for (uint16_t i = 0; i < 8; ++i) {
        Packet p;
        p.id = static_cast<uint16_t>(100 + i);
        p.payload = std::vector<uint8_t>(4, static_cast<uint8_t>(i + 1));
        inbox.push_back(p);
    }

    tag_and_log_NC(inbox);
    std::cout << "[NC] Done\n";
    return 0;
}