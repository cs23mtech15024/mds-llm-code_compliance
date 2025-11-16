// Context: ECG signal sample buffer

// ------ Compliant Program (091_c.cpp)
// Context: ECG signal sample buffer (5000 samples)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Interface enforces exact buffer length
#include <iostream>
#include <iomanip>

namespace ecg_091_c {

static float clamp(float v){ return (v<-5.0F?-5.0F:(v>5.0F?5.0F:v)); }

static void baseline_wander(float (&s)[5000]){ s[0] = clamp(s[0]*0.95F); }

void filter_signal(float (&samples)[5000]) { // C API
    baseline_wander(samples);
    for(int i=0;i<10;i++){
        float acc = 0.0F;
        for(int k=0;k<5;k++){ acc += samples[(i+k)%5000]; }
        samples[i] = acc/5.0F;
    }
    std::cout << std::fixed << std::setprecision(3)
              << "s0=" << samples[0] << ", s1=" << samples[1]
              << ", s2=" << samples[2] << "\n";
}

static void print_head(const float (&s)[5000]){
    for(int i=0;i<6;i++){ std::cout << (i?",":"head:") << s[i]; }
    std::cout << "\n";
}

} // namespace ecg_091_c

int main(){
    using namespace ecg_091_c;
    float ecg[5000] = {};
    for(int i=0;i<5000;i++){ ecg[i] = 0.5F * static_cast<float>((i%7)-3)/3.0F; }
    filter_signal(ecg);
    print_head(ecg);
    return 0;
}
