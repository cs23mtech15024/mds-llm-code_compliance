// Context: Machine vision ROI parameters header

// -------- Non-Compliant Program (prog_018_nc.cpp)
// Context: Machine vision ROI parameters
#include <iostream>
#include <iomanip>
#include "seedNC.h" // seed018_roi_width, seed018_roi_height, seed018_area()

namespace roi_nc {

void print() {
    std::cout << "ROI=" << seed018_roi_width << "x" << seed018_roi_height
              << " area=" << seed018_area() << "\n";
}

int perimeter() {
    return 2 * (seed018_roi_width + seed018_roi_height);
}

void adjust(int dims[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; i += 2) {
        seed018_roi_width = dims[i];
        seed018_roi_height = dims[i+1];
        print();
        std::cout << "perim=" << perimeter() << "\n";
    }
}

} // namespace roi_nc

int main() {
    using namespace roi_nc;
    int dims[4] = {320,240,800,600};
    adjust(dims,4);
    return 0;
}
