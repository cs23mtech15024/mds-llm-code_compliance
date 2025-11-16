// Context: Image processing kernel parameters

// -------- Compliant Program (prog_007_c.cpp)
// Context: Image processing kernel configuration
#include <iostream>
#include <vector>
#include <iomanip>
#include "seedC.h"

// Definitions
int   seed007_kernel_size  = 5;
float seed007_kernel_scale = 0.125F;
float seed007_scale_val(float v) { return v * seed007_kernel_scale; }

namespace img_c {

template <std::size_t N>
void process(const float (&buf)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        float v = seed007_scale_val(buf[i]) * seed007_kernel_size;
        std::cout << "p[" << i << "]=" << std::fixed << std::setprecision(4) << v << "\n";
    }
}

template <std::size_t N>
float average(const float (&buf)[N]) {
    float s = 0.0F;
    for (float v : buf) s += v;
    return (N>0) ? s/N : 0.0F;
}

} // namespace img_c

int main() {
    using namespace img_c;
    const float data[5] = {0.2F,0.4F,0.6F,0.8F,1.0F};
    process(data);
    std::cout << "avg=" << average(data) << "\n";
    return 0;
}
