// Context: Aerospace flight recorder timestamp validator

// ------ Non-Compliant Program (089_nc.cpp)
// Context: Aerospace flight recorder timestamp validator
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <vector>
#include <iomanip>

namespace app_089 {
    // Seed literals (NC): 0.05f, 1024u, 4096l
    constexpr float kRate = 0.05f;   // NC
    constexpr unsigned kSamples = 1024u; // NC
    constexpr long kBase = 4096l;    // NC

    struct Sample { long ts; float value; };

    void generate(std::vector<Sample>& buf) {
        long t = kBase;
        for (auto& s : buf) { s.ts = t; t += 1l; s.value = 1.0f; } // NC
    }

    void validate(const std::vector<Sample>& buf) {
        unsigned bad = 0u; // NC
        for (unsigned i = 1u; i < buf.size(); ++i) {
            long diff = buf[i].ts - buf[i-1u].ts; // NC
            if (diff != 1l) ++bad; // NC
        }
        std::cout << "[089] bad=" << bad << " rate=" << std::fixed
                  << std::setprecision(2) << kRate << '\n';
    }

    void run() {
        std::vector<Sample> buf(kSamples);
        generate(buf);
        validate(buf);
    }
}

int main() {
    app_089::run();
    return 0;
}
