// Context: Kalman filter state vector

// ------ Compliant Program (063_c.cpp)
// Context: Kalman state tweak and dump
// Rule: Preserve array via reference (COMPLIANT)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace kalman_063_c {

constexpr std::size_t kDim = 4U;

template <std::size_t N>
static void damp_first(float (&state)[N], float alpha) {
    static_assert(N == 4U, "state must be 4D");
    state[0] = state[0] * alpha;
}

template <std::size_t N>
static void add_bias(float (&state)[N], float b) {
    state[0] += b;
}

template <std::size_t N>
static void dump(const float (&state)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << (i?", ":"") << std::fixed << std::setprecision(3) << state[i];
    }
    std::cout << "\n";
}

void update_kalman_state(float (&state)[kDim]) { // C API
    damp_first(state, 0.99F);
    add_bias(state, 0.001F);
    dump(state);
}

} // namespace kalman_063_c

int main() {
    using namespace kalman_063_c;
    float x[kDim] = {1.0F, 0.5F, 0.0F, 0.0F};
    update_kalman_state(x);
    return 0;
}
