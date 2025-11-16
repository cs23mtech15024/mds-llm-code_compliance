// Context: Spindle speed feedback history

// ------ Non-Compliant Program (086_nc.cpp)
// Context: Spindle speed feedback history (50 samples)
// Rule: Array parameter decays to pointer (VIOLATION)
// Issue: Callee cannot enforce the 50-sample requirement
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace spindle_086_nc {

static int clip_rpm(int v){ return (v<0?0:(v>24000?24000:v)); }

static void normalize_first(int *speeds, std::size_t n){ if(n>0U){ speeds[0] = clip_rpm(speeds[0]); } }

// NC: "int speeds[]" loses bound info
void monitor_ramp(int speeds[]) { // NC API
    const std::size_t N = 50U; (void)N;
    normalize_first(speeds, 50U);
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

static void head(const int *v){
    for(int i=0;i<8;i++){ std::cout << (i?",":"head:") << v[i]; }
    std::cout << "\n";
}

} // namespace spindle_086_nc

int main(){
    using namespace spindle_086_nc;
    int rpms[50] = {3000};
    for(int i=1;i<50;i++){ rpms[i] = 3000 + (i*250)%5000; }
    monitor_ramp(rpms);
    head(rpms);
    return 0;
}
