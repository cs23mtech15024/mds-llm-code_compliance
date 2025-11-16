// Context: Camera autofocus region parameters

// -------- Non-Compliant Program (prog_035_nc.cpp)
// Context: Camera autofocus region params
#include <iostream>
#include "seedNC.h" // seed035_focus_x, seed035_focus_y, seed035_is_center()

namespace af_nc {

void adjust(int dx, int dy) {
    seed035_focus_x += dx;
    seed035_focus_y += dy;
}

void test(int moves[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; i += 2) {
        adjust(moves[i], moves[i+1]);
        std::cout << "pos=(" << seed035_focus_x << "," << seed035_focus_y << ")"
                  << " center=" << (seed035_is_center()?"Y":"N") << "\n";
    }
}

int sum(int arr[], std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace af_nc

int main() {
    using namespace af_nc;
    int mv[4] = {5,10,-20,-20};
    test(mv,4);
    std::cout << "sum=" << sum(mv,4) << "\n";
    return 0;
}
