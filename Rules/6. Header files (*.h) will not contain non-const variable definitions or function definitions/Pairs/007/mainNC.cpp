// Context: Image processing kernel parameters

// -------- Non-Compliant Program (prog_007_nc.cpp)
// Context: Image processing kernel configuration
#include <iostream>
#include <vector>
#include <iomanip>
#include "seedNC.h"  // seed007_kernel_size, seed007_kernel_scale, seed007_scale_val()

namespace img_nc {

float apply_kernel(float px) {
    return seed007_scale_val(px) * seed007_kernel_size;
}

void process(float* buf, std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        float v = apply_kernel(buf[i]);
        std::cout << "p[" << i << "]=" << std::fixed << std::setprecision(4) << v << "\n";
    }
}

float average(float* buf, std::size_t n) { // NC
    float s = 0.0F;
    for (std::size_t i = 0; i < n; ++i) s += buf[i];
    return (n>0) ? s/n : 0.0F;
}

} // namespace img_nc

int main() {
    using namespace img_nc;
    float data[5] = {0.2F,0.4F,0.6F,0.8F,1.0F};
    process(data,5);
    std::cout << "avg=" << average(data,5) << "\n";
    return 0;
}
