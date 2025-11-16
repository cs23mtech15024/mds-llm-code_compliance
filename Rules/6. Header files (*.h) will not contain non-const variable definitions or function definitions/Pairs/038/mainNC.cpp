// Context: Wearable device step detection threshold

// -------- Non-Compliant Program (prog_038_nc.cpp)
// Context: Wearable device step detection
#include <iostream>
#include "seedNC.h" // seed038_step_threshold, seed038_is_step()

namespace step_nc {

void detect(float vals[], std::size_t n) { // NC array decay
    for (std::size_t i = 0; i < n; ++i) {
        bool st = seed038_is_step(vals[i]);
        std::cout << "acc=" << vals[i] << " step=" << (st?"Y":"N") << "\n";
    }
}

float maxv(float arr[], std::size_t n) { // NC
    float m = 0.0F; for (std::size_t i=0;i<n;++i) if(arr[i]>m) m=arr[i]; return m;
}

} // namespace step_nc

int main() {
    using namespace step_nc;
    float a[6] = {0.8F,1.0F,1.4F,1.6F,1.2F,0.7F};
    detect(a,6);
    std::cout << "max=" << maxv(a,6) << "\n";
    return 0;
}
