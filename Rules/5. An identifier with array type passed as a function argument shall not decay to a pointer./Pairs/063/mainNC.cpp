// Context: Kalman filter state vector

// ------ Non-Compliant Program (063_nc.cpp)
// Context: Kalman state tweak and dump
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace kalman_063_nc {

constexpr std::size_t kDim = 4U;

static void damp_first(float *state, std::size_t n, float alpha) { // NC
    if (n > 0U) { state[0] = state[0] * alpha; }
}

static void add_bias(float *state, std::size_t n, float b) { // NC
    if (n > 0U) { state[0] += b; }
}

static void dump(const float *state, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << (i?", ":"") << std::fixed << std::setprecision(3) << state[i];
    }
    std::cout << "\n";
}

void update_kalman_state(float state[]) { // NC API
    damp_first(state, kDim, 0.99F);
    add_bias(state, kDim, 0.001F);
    dump(state, kDim);
}

} // namespace kalman_063_nc

int main() {
    using namespace kalman_063_nc;
    float x[kDim] = {1.0F, 0.5F, 0.0F, 0.0F};
    update_kalman_state(x);
    return 0;
}
