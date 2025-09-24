// ------ Non-Compliant
// Seed: Non-compliant: unsigned _packetId = 0;   // Compliant: unsigned packetId = 0;
// Context: Packet header processing helper used in a DRDO tactical link-layer module.
// Violation: identifier begins with '_' — reserved/implementation identifiers must not be used (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:8‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          cppreference — identifier reservation rules.  [oai_citation:9‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow: rules about underscores in C++ identifiers.  [oai_citation:10‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance on reserved identifiers.  [oai_citation:11‡PVS-Studio](https://pvs-studio.com/en/docs/manual/full/?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>

namespace drdo {
    struct Packet {
        uint16_t src;
        uint16_t dst;
        uint8_t  type;
        std::vector<uint8_t> payload;
    };

    inline uint16_t checksum(const Packet &p) {
        uint16_t sum = 0;
        for (uint8_t b : p.payload) sum = static_cast<uint16_t>((sum + b) & 0xFFFFu);
        sum ^= p.src;
        sum ^= p.dst;
        sum ^= p.type;
        return sum;
    }
}

// Non-compliant: static identifier uses leading underscore (seed)
static unsigned _packetId = 0; // NON-COMPLIANT: leading underscore in identifier (seed)

void process_packets_NC(const std::vector<drdo::Packet> &inbox) {
    std::ofstream log("packet_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < inbox.size(); ++i) {
        drdo::Packet p = inbox[i];

        // attach deterministic packet id and compute checksum
        p.payload.push_back(static_cast<uint8_t>(_packetId & 0xFFu));
        p.payload.push_back(static_cast<uint8_t>((_packetId >> 8) & 0xFFu));
        uint16_t cs = drdo::checksum(p);

        log << "[NC] idx=" << i << " pktId=" << _packetId << " chk=0x" << std::hex << cs << std::dec << '\n';
        std::cout << "[NC] processed idx=" << i << " pktId=" << _packetId << '\n';

        // increment packet id deterministically
        _packetId = (_packetId + 1u) & 0xFFFFu;

        // simulate small processing time
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }

    log.close();
}

int main() {
    // deterministic synthetic inbox
    std::vector<drdo::Packet> inbox;
    for (int i = 0; i < 8; ++i) {
        drdo::Packet p;
        p.src = static_cast<uint16_t>(1000 + i);
        p.dst = 2000;
        p.type = static_cast<uint8_t>(i % 4);
        p.payload = std::vector<uint8_t>(4, static_cast<uint8_t>(i + 10));
        inbox.push_back(p);
    }

    process_packets_NC(inbox);
    std::cout << "[NC] Done\n";
    return 0;
}