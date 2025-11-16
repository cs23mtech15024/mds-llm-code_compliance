// Context: Drone propeller pitch lookup header

// -------- Compliant Program (prog_067_c.cpp)
#include <iostream>
#include "seedC.h"

float seed067_pitch_values[3]={3.1F,4.5F,5.2F};
float seed067_get_pitch(int i){ return seed067_pitch_values[i]; }

namespace pitch_c {

template <std::size_t N>
void test(const int (&idx)[N]){
    for(auto v:idx){
        float p = seed067_get_pitch(v);
        std::cout << "idx=" << v
                  << " p=" << p
                  << " v0=" << seed067_pitch_values[0]
                  << "\n";
    }
}

template <std::size_t N>
int maxidx(const int (&arr)[N]){ int m=arr[0]; for(auto v:arr) if(v>m)m=v; return m; }

} // namespace pitch_c

int main(){
    using namespace pitch_c;
    const int i[5]={0,1,2,1,0};
    test(i);
    std::cout << "maxidx=" << maxidx(i)<<"\n";
    return 0;
}
