// Context: Wearable device step detection threshold

// -------- Compliant Program (prog_038_c.cpp)
// Context: Wearable device step detection — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
float seed038_step_threshold = 1.3F;
bool seed038_is_step(float v) { return v > seed038_step_threshold; }

namespace step_c {

template <std::size_t N>
void detect(const float (&vals)[N]) {
    for (auto v : vals) {
        bool st = seed038_is_step(v);
        std::cout << "acc=" << v << " step=" << (st?"Y":"N") << "\n";
    }
}

template <std::size_t N>
float maxv(const float (&arr)[N]) {
    float m = 0.0F; for (auto v : arr) if (v > m) m = v; return m;
}

} // namespace step_c

int main() {
    using namespace step_c;
    const float a[6] = {0.8F,1.0F,1.4F,1.6F,1.2F,0.7F};
    detect(a);
    std::cout << "max=" << maxv(a) << "\n";
    return 0;
}
