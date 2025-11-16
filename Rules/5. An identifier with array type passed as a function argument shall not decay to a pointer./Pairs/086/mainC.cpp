// Context: Spindle speed feedback history

// ------ Compliant Program (086_c.cpp)
// Context: Spindle speed feedback history (50 samples)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Type guarantees exactly 50 elements
#include <iostream>
#include <iomanip>

namespace spindle_086_c {

static int clip_rpm(int v){ return (v<0?0:(v>24000?24000:v)); }

static void normalize_first(int (&speeds)[50]){ speeds[0] = clip_rpm(speeds[0]); }

void monitor_ramp(int (&speeds)[50]) { // C API
    normalize_first(speeds);
    int mn = speeds[0], mx = speeds[0];
    long sum = 0L;
    for(int i=0;i<10;i++){
        if(speeds[i] < mn) mn = speeds[i];
        if(speeds[i] > mx) mx = speeds[i];
        sum += speeds[i];
    }
    double avg10 = static_cast<double>(sum)/10.0;
    std::cout << std::fixed << std::setprecision(1)
              << "rpm0=" << speeds[0]
              << ", min10=" << mn
              << ", max10=" << mx
              << ", avg10=" << avg10 << "\n";
}

static void head(const int (&v)[50]){
    for(int i=0;i<8;i++){ std::cout << (i?",":"head:") << v[i]; }
    std::cout << "\n";
}

} // namespace spindle_086_c

int main(){
    using namespace spindle_086_c;
    int rpms[50] = {3000};
    for(int i=1;i<50;i++){ rpms[i] = 3000 + (i*250)%5000; }
    monitor_ramp(rpms);
    head(rpms);
    return 0;
}
