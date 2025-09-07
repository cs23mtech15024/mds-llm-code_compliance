// ------ Non-Compliant
// Pair 20 — Seed: 0x1Afu -> 0x1AFU
// Context: Checksum mask for tactical communication frames in a DRDO secure-comm module.
// Violation: lowercase hex letters and lowercase 'u' suffix reduce readability.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case) and JSF-AV hex guidance.

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

// Small secure-comm helper showing mask usage — non-compliant literal included
class FrameChecksum_NC {
public:
    // non-compliant mask: lowercase hex letters + lowercase 'u' suffix
    static constexpr uint32_t CHECK_MASK = 0x1Afu; // NC: seed literal

    // Compute a trivial checksum (XOR of words) then apply mask
    uint32_t computeChecksum(const std::vector<uint8_t>& payload) const {
        uint32_t acc = 0u;
        for (size_t i = 0u; i < payload.size(); ++i) {
            acc ^= static_cast<uint32_t>(payload[i]) << ((i % 4u) * 8u);
        }
        // mask result with non-compliant literal
        return acc & CHECK_MASK;
    }

    bool verify(const std::vector<uint8_t>& payload, uint32_t received) const {
        return computeChecksum(payload) == (received & CHECK_MASK);
    }

    void demo() const {
        std::vector<uint8_t> frame = { 0x10u, 0x20u, 0x30u, 0x40u, 0x55u }; // NC: unsigned suffixes lowercase
        uint32_t cs = computeChecksum(frame);
        std::cout << "[NC] CHECK_MASK = 0x" << std::hex << CHECK_MASK << std::dec << "\n";
        std::cout << "[NC] computed cs = 0x" << std::hex << cs << std::dec << "\n";
        std::cout << "[NC] verify = " << (verify(frame, cs) ? "PASS" : "FAIL") << "\n";
    }
};

int main() {
    FrameChecksum_NC helper;
    helper.demo();
    return 0;
}