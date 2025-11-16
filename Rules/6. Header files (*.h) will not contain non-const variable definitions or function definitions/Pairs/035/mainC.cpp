// Context: Camera autofocus region parameters

// -------- Compliant Program (prog_035_c.cpp)
// Context: Camera autofocus region params — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed035_focus_x = 120;
int seed035_focus_y = 220;
bool seed035_is_center() { return seed035_focus_x > 100 && seed035_focus_y > 100; }

namespace af_c {

void adjust(int dx, int dy) {
    seed035_focus_x += dx;
    seed035_focus_y += dy;
}

template <std::size_t N>
void test(const int (&moves)[N]) {
    for (std::size_t i = 0; i < N; i += 2) {
        adjust(moves[i], moves[i+1]);
        std::cout << "pos=(" << seed035_focus_x << "," << seed035_focus_y << ")"
                  << " center=" << (seed035_is_center()?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]) {
    int s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace af_c

int main() {
    using namespace af_c;
    const int mv[4] = {5,10,-20,-20};
    test(mv);
    std::cout << "sum=" << sum(mv) << "\n";
    return 0;
}
