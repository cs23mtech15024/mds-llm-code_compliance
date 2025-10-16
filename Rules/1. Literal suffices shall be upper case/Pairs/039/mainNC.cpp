// ------ Non-Compliant (Seed 039)
// Context: Networking — compute TCP-style smoothed RTT (SRTT), RTT variance, and RTO with backoff.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in 0xffu.

#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>

struct RtoParams {
    float alpha;           // EWMA factor for SRTT
    float beta;            // scale factor for RTTVAR
    unsigned dbg_mask;     // pretend color/debug mask
    long ms_per_sec;       // milliseconds per second
};

class RtoCalc {
public:
    explicit RtoCalc(const RtoParams& p)
        : prm(p), srtt_ms(0.0f), rttvar_ms(0.0f), rto_ms(1000.0f) {} // non-compliant

    void observe(float rtt_ms_sample) {
        if (first) {
            srtt_ms = rtt_ms_sample;
            rttvar_ms = rtt_ms_sample * 0.5f; // non-compliant
            first = false;
        } else {
            float err = rtt_ms_sample - srtt_ms;
            rttvar_ms = (1.0f - prm.alpha) * rttvar_ms + prm.alpha * std::abs(err);
            srtt_ms   = (1.0f - prm.alpha) * srtt_ms   + prm.alpha * rtt_ms_sample;
        }
        rto_ms = std::min(srtt_ms + prm.beta * rttvar_ms, 200.0f, 60000.0f); // non-compliant
        (void)prm.dbg_mask; // just to use it
    }

    float rto() const { return rto_ms; }

private:
    RtoParams prm;
    bool first { true };
    float srtt_ms;
    float rttvar_ms;
    float rto_ms;
};

int main() {
    RtoParams prm{0.125f, 1.5f, 0xffu, 1000l}; // non-compliant
    RtoCalc calc(prm);

    const std::array<float, 6> samples{120.0f, 130.0f, 200.0f, 95.0f, 110.0f, 400.0f}; // non-compliant
    for (float s : samples) {
        calc.observe(s);
        std::cout << std::fixed << std::setprecision(2)
                  << "Sample=" << s << " ms -> RTO=" << calc.rto() << " ms\n";
    }
    return 0;
}