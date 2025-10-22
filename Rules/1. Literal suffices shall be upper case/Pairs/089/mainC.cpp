// Context: Aerospace flight recorder timestamp validator

// ------ Compliant Program (089_c.cpp)
// Context: Aerospace flight recorder timestamp validator
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <vector>
#include <iomanip>

namespace app_089 {
    // Seed literals (C): 0.05F, 1024U, 4096L
    constexpr float kRate = 0.05F;   // C
    constexpr unsigned kSamples = 1024U; // C
    constexpr long kBase = 4096L;    // C

    struct Sample { long ts; float value; };

    void generate(std::vector<Sample>& buf) {
        long t = kBase;
        for (auto& s : buf) { s.ts = t; t += 1L; s.value = 1.0F; } // C
    }

    void validate(const std::vector<Sample>& buf) {
        unsigned bad = 0U; // C
        for (unsigned i = 1U; i < buf.size(); ++i) {
            long diff = buf[i].ts - buf[i-1U].ts; // C
            if (diff != 1L) ++bad; // C
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
