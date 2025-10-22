// ------ Non-Compliant (Seed 021)
// Context: Networking — simple packet transmission simulator with artificial packet loss.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase literal suffixes 'f', 'u', and 'l' used.

#include <iostream>
#include <cstdlib>
#include <ctime>

struct Packet {
    unsigned id;
    bool dropped;
};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const float lossRate = 0.05f; // 5% chance of packet drop (non-compliant)
    const unsigned totalPackets = 100u; // should be 100U
    const long seedAdjust = 1l;         // should be 1L
    (void)seedAdjust;

    unsigned droppedCount = 0u; // should be 0U

    for (unsigned i = 0u; i < totalPackets; ++i) {
        Packet p{i, false};
        float r = static_cast<float>(std::rand()) / RAND_MAX;

        if (r < lossRate) {
            p.dropped = true;
            ++droppedCount;
        }
    }

    const float lossPercent = (static_cast<float>(droppedCount) / totalPackets) * 100.0f; // 100.0f non-compliant
    std::cout << "Packets dropped: " << droppedCount << "/" << totalPackets
              << " (" << lossPercent << "%)\n";

    return 0;
}