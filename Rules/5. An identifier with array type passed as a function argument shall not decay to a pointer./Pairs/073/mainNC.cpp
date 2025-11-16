// Context: Inverter switching frequency table

// ------ Non-Compliant Program (073_nc.cpp)
// Context: Inverter switching frequency table
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstddef>

namespace inv_073_nc {

static void clamp(int &v, int lo, int hi) { if (v < lo) v = lo; if (v > hi) v = hi; }

void set_switching_freq(int frequencies[]) { // NC API
    const std::size_t N = 10U; (void)N;
    frequencies[0] = 20000; // 20 kHz
    clamp(frequencies[0], 1000, 100000);
    std::cout << "freq=" << frequencies[0] << "Hz\n";
}

static void show(const int *f, std::size_t n) {
    for (std::size_t i=0;i<n && i<4;i++){ std::cout << (i?",":"head:") << f[i]; }
    std::cout << "\n";
}

} // namespace inv_073_nc

int main(){
    using namespace inv_073_nc;
    int inverter_freqs[10] = {0};
    set_switching_freq(inverter_freqs);
    show(inverter_freqs, 10U);
    return 0;
}
