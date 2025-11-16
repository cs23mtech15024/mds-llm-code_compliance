// Context: Printer nozzle temperature zones

// ------ Compliant Program (094_c.cpp)
// Context: Printer nozzle temperature zones (5 zones)
// Status: Array passed by reference (COMPLIANT)
// Outcome: Compiler enforces five-zone array
#include <iostream>
#include <iomanip>

namespace nozzle_094_c {

static int clamp_c(int v){ return (v<0?0:(v>300?300:v)); }

static void set_zone0(int (&t)[5]){ t[0] = clamp_c(210); }

void calibrate_hotend(int (&temperatures)[5]) { // C API
    set_zone0(temperatures);
    long sum = 0L;
    for(int i=0;i<5;i++){ sum += temperatures[i]; }
    double avg = static_cast<double>(sum)/5.0;
    std::cout << "nozzle0=" << temperatures[0] << ", avg=" << avg << "\n";
}

static void print_z(const int (&t)[5]){
    for(int i=0;i<5;i++){ std::cout << (i?",":"zones:") << t[i]; }
    std::cout << "\n";
}

} // namespace nozzle_094_c

int main(){
    using namespace nozzle_094_c;
    int zones[5] = {0,200,205,210,215};
    calibrate_hotend(zones);
    print_z(zones);
    return 0;
}
