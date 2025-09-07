// ------ Compliant
// Pair 20 — Seed: 0x1Afu -> 0x1AFU
// Context: Checksum mask for tactical communication frames in a DRDO secure-comm module.
// Violation: lowercase hex letters and lowercase 'u' suffix reduce readability.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case) and JSF-AV hex guidance.

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

// Small secure-comm helper showing mask usage — compliant literal included
class FrameChecksum_C {
public:
    // compliant mask: uppercase hex letters + uppercase 'U' suffix
    static constexpr uint32_t CHECK_MASK = 0x1AFU; // C: seed corrected

    // Compute a trivial checksum (XOR of words) then apply mask
    uint32_t computeChecksum(const std::vector<uint8_t>& payload) const {
        uint32_t acc = 0U;
        for (size_t i = 0U; i < payload.size(); ++i) {
            acc ^= static_cast<uint32_t>(payload[i]) << ((i % 4U) * 8U);
        }
        // mask result with compliant literal
        return acc & CHECK_MASK;
    }

    bool verify(const std::vector<uint8_t>& payload, uint32_t received) const {
        return computeChecksum(payload) == (received & CHECK_MASK);
    }

    void demo() const {
        std::vector<uint8_t> frame = { 0x10U, 0x20U, 0x30U, 0x40U, 0x55U }; // C: uppercase suffixes
        uint32_t cs = computeChecksum(frame);
        std::cout << "[C] CHECK_MASK = 0x" << std::hex << CHECK_MASK << std::dec << "\n";
        std::cout << "[C] computed cs = 0x" << std::hex << cs << std::dec << "\n";
        std::cout << "[C] verify = " << (verify(frame, cs) ? "PASS" : "FAIL") << "\n";
    }
};

int main() {
    FrameChecksum_C helper;
    helper.demo();
    return 0;
}