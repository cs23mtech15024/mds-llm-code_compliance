// Context: Car infotainment audio buffer size header

// -------- Compliant Program (prog_061_c.cpp)
#include <iostream>
#include "seedC.h"

int seed061_audio_buffer = 2048;
int seed061_half_buffer(){ return seed061_audio_buffer/2; }

namespace audio_c {

template <std::size_t N>
void process(const int (&samples)[N]) {
    for (auto s : samples) {
        int half = seed061_half_buffer();
        std::cout << "sample=" << s
                  << " buf=" << seed061_audio_buffer
                  << " half=" << half << "\n";
    }
}

template <std::size_t N>
int peak(const int (&arr)[N]){
    int m = arr[0];
    for(auto v:arr) if(v>m) m=v;
    return m;
}

} // namespace audio_c

int main(){
    using namespace audio_c;
    const int s[5]={12,18,22,30,25};
    process(s);
    std::cout << "peak=" << peak(s) << "\n";
    return 0;
}
