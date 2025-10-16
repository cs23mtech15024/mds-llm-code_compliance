// ------ Non-Compliant (Seed 036)
// Context: Networking — simple TCP retransmission timer simulation with backoff and retry limit.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in 0xffu.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

struct TcpPolicy {
    float initial_rto_s;     // initial retransmission timeout in seconds
    unsigned max_retries;    // maximum retransmissions
    unsigned ack_mask;       // simulated ACK flag mask
    long backoff_limit;      // max exponential backoff factor
};

class TcpSimulator {
public:
    explicit TcpSimulator(const TcpPolicy& p) : pol_(p) {}

    void runSimulation(unsigned ack_flags) {
        float rto = pol_.initial_rto_s;
        unsigned retry = 0u;   // non-compliant 'u'
        std::cout << "Initial RTO=" << rto << "s\n";

        while (retry < pol_.max_retries) {
            bool acked = (ack_flags & pol_.ack_mask) != 0u; // non-compliant
            if (acked) {
                std::cout << "ACK received at retry " << retry << "\n";
                return;
            } else {
                std::cout << "Timeout at retry " << retry
                          << ", backoff to " << rto << "s\n";
                retry++;
                rto *= 2.0f; // non-compliant 'f'
                if (rto > static_cast<float>(pol_.backoff_limit * 1l)) break; // non-compliant 'l'
            }
        }
        std::cout << "Connection failed after " << retry << " retries.\n";
    }

private:
    TcpPolicy pol_;
};

int main() {
    TcpPolicy pol{};
    pol.initial_rto_s = 0.25f;   // non-compliant
    pol.max_retries   = 5u;      // non-compliant
    pol.ack_mask      = 0xffu;   // non-compliant
    pol.backoff_limit = 16l;     // non-compliant

    TcpSimulator sim(pol);
    sim.runSimulation(0x00u);    // non-compliant
    return 0;
}