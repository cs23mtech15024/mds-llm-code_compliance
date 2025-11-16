// Context: Machine vision ROI parameters header

// -------- Compliant Program (prog_018_c.cpp)
// Context: Machine vision ROI parameters — COMPLIANT
#include <iostream>
#include <iomanip>
#include "seedC.h" // extern seed018_roi_width, seed018_roi_height, seed018_area()

// Definitions
int seed018_roi_width = 640;
int seed018_roi_height = 480;
int seed018_area() { return seed018_roi_width * seed018_roi_height; }

namespace roi_c {

void print() {
    std::cout << "ROI=" << seed018_roi_width << "x" << seed018_roi_height
              << " area=" << seed018_area() << "\n";
}

template <std::size_t N>
void adjust(const int (&dims)[N]) {
    for (std::size_t i = 0; i < N; i += 2) {
        seed018_roi_width = dims[i];
        seed018_roi_height = dims[i+1];
        print();
        int per = 2 * (seed018_roi_width + seed018_roi_height);
        std::cout << "perim=" << per << "\n";
    }
}

} // namespace roi_c

int main() {
    using namespace roi_c;
    const int dims[4] = {320,240,800,600};
    adjust(dims);
    return 0;
}
