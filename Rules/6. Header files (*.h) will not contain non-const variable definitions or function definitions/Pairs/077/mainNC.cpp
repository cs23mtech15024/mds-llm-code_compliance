// Context: Medical heart rate smoothing factor

// -------- Non-Compliant Program (prog_077_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed077_smooth_factor, seed077_smooth()

namespace hr_nc {

void smooth(float data[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        float out = seed077_smooth(data[i]);
        std::cout << "raw=" << data[i]
                  << " fact=" << seed077_smooth_factor
                  << " sm=" << out << "\n";
    }
}

float avg(float a[], std::size_t n){ float s=0; for(size_t i=0;i<n;++i) s+=a[i]; return n? s/n : 0; }

} // namespace hr_nc

int main(){
    using namespace hr_nc;
    float beats[6] = {72.0F, 75.0F, 80.0F, 77.0F, 74.0F, 76.0F};
    smooth(beats,6);
    std::cout << "avg=" << avg(beats,6) << "\n";
    return 0;
}
