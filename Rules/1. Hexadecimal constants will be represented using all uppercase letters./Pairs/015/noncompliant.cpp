// ------ Non-Compliant
// Pair 15 — Seed: 0u -> 0U
// Context: Header flag in quantum key generation packet for DRDO QKD protocol.
// Violation: lowercase 'u' suffix ambiguous in embedded bitfields.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <cstdint>
#include <bitset>

struct QKDHeader_NC {
    unsigned version : 4;
    unsigned flag : 4;
    unsigned reserved : 8;
    QKDHeader_NC() : version(1u), flag(0u), reserved(0u) {} // NC: lowercase 'u'
};

class PacketProcessor_NC {
public:
    void encode(const QKDHeader_NC &hdr) {
        uint16_t raw = (hdr.version & 0xFu) << 12 | (hdr.flag & 0xFu) << 8 | hdr.reserved; // NC
        std::cout << "[NC] Encoded header: 0b" << std::bitset<16>(raw) << "\n";
    }

    void decode(uint16_t raw) {
        QKDHeader_NC hdr;
        hdr.version = (raw >> 12) & 0xFu; // NC
        hdr.flag = (raw >> 8) & 0xFu;     // NC
        hdr.reserved = raw & 0xFFu;       // NC
        std::cout << "[NC] Decoded header - version: " << hdr.version
                  << ", flag: " << hdr.flag
                  << ", reserved: " << hdr.reserved << "\n";
    }
};

int main() {
    QKDHeader_NC hdr;
    hdr.flag = 5u; // NC
    PacketProcessor_NC proc;
    proc.encode(hdr);
    proc.decode(0x1F5Au);
    return 0;
}