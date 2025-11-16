// Context: Inverter switching frequency table

// ------ Compliant Program (073_c.cpp)
// Context: Inverter switching frequency table
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstddef>

namespace inv_073_c {

static void clamp(int &v, int lo, int hi) { if (v < lo) v = lo; if (v > hi) v = hi; }

void set_switching_freq(int (&frequencies)[10]) { // C API
    frequencies[0] = 20000;
    clamp(frequencies[0], 1000, 100000);
    std::cout << "freq=" << frequencies[0] << "Hz\n";
}

static void show(const int (&f)[10]) {
    for (int i=0;i<4;i++){ std::cout << (i?",":"head:") << f[i]; }
    std::cout << "\n";
}

} // namespace inv_073_c

int main(){
    using namespace inv_073_c;
    int inverter_freqs[10] = {0};
    set_switching_freq(inverter_freqs);
    show(inverter_freqs);
    return 0;
}
