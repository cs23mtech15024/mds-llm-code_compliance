// Context: Runway lighting intensity scheduler

// ------ Compliant Program (055_c.cpp)
// Compliant: single declarator per declaration.
#include <iostream>
#include <array>
#include <algorithm>
namespace lights_055 {
    struct Phase { unsigned east; unsigned west; }; // OK
    static float clampf(float v){ return std::max(0.5F,std::min(2.0F,v)); }
    void schedule(){
        unsigned east=10U;                       // C
        unsigned west=8U;                        // C
        float bias=1.0F;                         // C
        float step=0.0F;                         // C
        bool fog=false;                          // C
        bool night=true;                         // C
        std::array<unsigned,8U> q{9,12,14,7,6,11,10,15};
        for (std::size_t i=0;i<q.size();++i){
            step = (q[i]>10U)?0.1F:-0.1F; bias = clampf(bias + step);
            east += (i%2U)?1U:0U; west += (i%2U)?0U:1U;
            if (q[i]>13U){ fog=true; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" bias="<<bias<<" E="<<east<<" W="<<west<<"\n"; }
        }
        std::cout<<"fog="<<fog<<" night="<<night<<"\n";
    }
}
int main(){ lights_055::schedule(); return 0; }
