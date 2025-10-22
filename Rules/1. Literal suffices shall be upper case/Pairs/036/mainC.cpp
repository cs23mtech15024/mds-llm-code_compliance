// ------ Compliant (Seed 036)
// Context: Networking — simple TCP retransmission timer simulation with backoff and retry limit.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes uppercase ('F','U','L') and hex digits to uppercase (0XFFU).

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

struct TcpPolicy {
    float initial_rto_s;
    unsigned max_retries;
    unsigned ack_mask;
    long backoff_limit;
};

class TcpSimulator {
public:
    explicit TcpSimulator(const TcpPolicy& p) : pol_(p) {}

    void runSimulation(unsigned ack_flags) {
        float rto = pol_.initial_rto_s;
        unsigned retry = 0U;   // compliant
        std::cout << "Initial RTO=" << rto << "s\n";

        while (retry < pol_.max_retries) {
            bool acked = (ack_flags & pol_.ack_mask) != 0U; // compliant
            if (acked) {
                std::cout << "ACK received at retry " << retry << "\n";
                return;
            } else {
                std::cout << "Timeout at retry " << retry
                          << ", backoff to " << rto << "s\n";
                retry++;
                rto *= 2.0F; // compliant
                if (rto > static_cast<float>(pol_.backoff_limit * 1L)) break; // compliant
            }
        }
        std::cout << "Connection failed after " << retry << " retries.\n";
    }

private:
    TcpPolicy pol_;
};

int main() {
    TcpPolicy pol{};
    pol.initial_rto_s = 0.25F;   // compliant
    pol.max_retries   = 5U;      // compliant
    pol.ack_mask      = 0XFFU;   // compliant
    pol.backoff_limit = 16L;     // compliant

    TcpSimulator sim(pol);
    sim.runSimulation(0X00U);    // compliant
    return 0;
}