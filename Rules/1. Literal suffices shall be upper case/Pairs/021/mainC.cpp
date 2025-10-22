// ------ Compliant (Seed 021)
// Context: Networking — simple packet transmission simulator with artificial packet loss.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F, U, and L.

#include <iostream>
#include <cstdlib>
#include <ctime>

struct Packet {
    unsigned id;
    bool dropped;
};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const float lossRate = 0.05F; // compliant
    const unsigned totalPackets = 100U; // compliant
    const long seedAdjust = 1L;         // compliant
    (void)seedAdjust;

    unsigned droppedCount = 0U; // compliant

    for (unsigned i = 0U; i < totalPackets; ++i) {
        Packet p{i, false};
        float r = static_cast<float>(std::rand()) / RAND_MAX;

        if (r < lossRate) {
            p.dropped = true;
            ++droppedCount;
        }
    }

    const float lossPercent = (static_cast<float>(droppedCount) / totalPackets) * 100.0F; // compliant
    std::cout << "Packets dropped: " << droppedCount << "/" << totalPackets
              << " (" << lossPercent << "%)\n";

    return 0;
}