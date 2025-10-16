// ------ Compliant (Seed 039)
// Context: Networking — compute TCP-style smoothed RTT (SRTT), RTT variance, and RTO with backoff.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: uppercase literal suffixes ('F','U','L') and uppercase hex digits (0XFFU).

#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>

struct RtoParams {
    float alpha;
    float beta;
    unsigned dbg_mask;
    long ms_per_sec;
};

class RtoCalc {
public:
    explicit RtoCalc(const RtoParams& p)
        : prm(p), srtt_ms(0.0F), rttvar_ms(0.0F), rto_ms(1000.0F) {}

    void observe(float rtt_ms_sample) {
        if (first) {
            srtt_ms = rtt_ms_sample;
            rttvar_ms = rtt_ms_sample * 0.5F;
            first = false;
        } else {
            float err = rtt_ms_sample - srtt_ms;
            rttvar_ms = (1.0F - prm.alpha) * rttvar_ms + prm.alpha * std::abs(err);
            srtt_ms   = (1.0F - prm.alpha) * srtt_ms   + prm.alpha * rtt_ms_sample;
        }
        rto_ms = std::min(srtt_ms + prm.beta * rttvar_ms, 200.0F, 60000.0F);
        (void)prm.dbg_mask;
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
    RtoParams prm{0.125F, 1.5F, 0XFFU, 1000L};
    RtoCalc calc(prm);

    const std::array<float, 6> samples{120.0F, 130.0F, 200.0F, 95.0F, 110.0F, 400.0F};
    for (float s : samples) {
        calc.observe(s);
        std::cout << std::fixed << std::setprecision(2)
                  << "Sample=" << s << " ms -> RTO=" << calc.rto() << " ms\n";
    }
    return 0;
}