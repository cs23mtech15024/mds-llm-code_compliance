// Context: Printer nozzle temperature zones

// ------ Non-Compliant Program (094_nc.cpp)
// Context: Printer nozzle temperature zones (5 zones)
// Rule: Array parameter decays to pointer (VIOLATION)
// Problem: Calibration assumes exactly five zones
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace nozzle_094_nc {

static int clamp_c(int v){ return (v<0?0:(v>300?300:v)); }

static void set_zone0(int *t, std::size_t n){ if(n>0U){ t[0] = clamp_c(210); } }

void calibrate_hotend(int temperatures[]) { // NC API
    const std::size_t Z = 5U; (void)Z;
    set_zone0(temperatures, 5U);
    long sum = 0L;
    for(int i=0;i<5;i++){ sum += temperatures[i]; }
    double avg = static_cast<double>(sum)/5.0;
    std::cout << "nozzle0=" << temperatures[0] << ", avg=" << avg << "\n";
}

static void print_z(const int *t){
    for(int i=0;i<5;i++){ std::cout << (i?",":"zones:") << t[i]; }
    std::cout << "\n";
}

} // namespace nozzle_094_nc

int main(){
    using namespace nozzle_094_nc;
    int zones[5] = {0,200,205,210,215};
    calibrate_hotend(zones);
    print_z(zones);
    return 0;
}
