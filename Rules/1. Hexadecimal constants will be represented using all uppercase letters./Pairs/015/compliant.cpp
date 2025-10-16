// ------ Compliant
// Pair 15 — Seed: 0u -> 0U
// Context: Header flag in quantum key generation packet for DRDO QKD protocol.
// Violation: lowercase 'u' suffix ambiguous in embedded bitfields.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <cstdint>
#include <bitset>

struct QKDHeader_C {
    unsigned version : 4;
    unsigned flag : 4;
    unsigned reserved : 8;
    QKDHeader_C() : version(1U), flag(0U), reserved(0U) {} // C: uppercase 'U'
};

class PacketProcessor_C {
public:
    void encode(const QKDHeader_C &hdr) {
        uint16_t raw = (hdr.version & 0xFU) << 12 | (hdr.flag & 0xFU) << 8 | hdr.reserved; // C
        std::cout << "[C] Encoded header: 0b" << std::bitset<16>(raw) << "\n";
    }

    void decode(uint16_t raw) {
        QKDHeader_C hdr;
        hdr.version = (raw >> 12) & 0xFU; // C
        hdr.flag = (raw >> 8) & 0xFU;     // C
        hdr.reserved = raw & 0xFFU;       // C
        std::cout << "[C] Decoded header - version: " << hdr.version
                  << ", flag: " << hdr.flag
                  << ", reserved: " << hdr.reserved << "\n";
    }
};

int main() {
    QKDHeader_C hdr;
    hdr.flag = 5U; // C
    PacketProcessor_C proc;
    proc.encode(hdr);
    proc.decode(0x1F5AU);
    return 0;
}