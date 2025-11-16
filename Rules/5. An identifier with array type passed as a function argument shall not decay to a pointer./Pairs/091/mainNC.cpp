// Context: ECG signal sample buffer

// ------ Non-Compliant Program (091_nc.cpp)
// Context: ECG signal sample buffer (5000 samples)
// Rule: Array parameter decays to pointer (VIOLATION)
// Issue: Filter assumes 5000 points but type does not
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace ecg_091_nc {

// Simple clamp to avoid absurd values from sensor spikes
static float clamp(float v){ return (v<-5.0F?-5.0F:(v>5.0F?5.0F:v)); }

// NC helper that relies on caller passing correct n
static void baseline_wander(float *s, std::size_t n){ if(n>0U){ s[0] = clamp(s[0]*0.95F); } }

// NC: array parameter decays to pointer; no compile-time bound check
void filter_signal(float samples[]) { // NC API
    const std::size_t N = 5000U; (void)N;
    baseline_wander(samples, 5000U);
    // Apply a tiny 5-tap moving average to the first 10 samples for demo
    for(int i=0;i<10;i++){
        float acc = 0.0F;
        for(int k=0;k<5;k++){ acc += samples[(i+k)%5000]; }
        samples[i] = acc/5.0F;
    }
    // Report first three values
    std::cout << std::fixed << std::setprecision(3)
              << "s0=" << samples[0] << ", s1=" << samples[1]
              << ", s2=" << samples[2] << "\n";
}

static void print_head(const float *s){
    for(int i=0;i<6;i++){ std::cout << (i?",":"head:") << s[i]; }
    std::cout << "\n";
}

} // namespace ecg_091_nc

int main(){
    using namespace ecg_091_nc;
    float ecg[5000] = {};
    for(int i=0;i<5000;i++){ ecg[i] = 0.5F * static_cast<float>((i%7)-3)/3.0F; }
    filter_signal(ecg);
    print_head(ecg);
    return 0;
}
