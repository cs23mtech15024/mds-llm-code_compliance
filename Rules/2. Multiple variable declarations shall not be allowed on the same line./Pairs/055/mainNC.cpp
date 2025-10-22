// Context: Runway lighting intensity scheduler

// ------ Non-Compliant Program (055_nc.cpp)
// 8-0-1 violation via multi-declarator lines.
#include <iostream>
#include <array>
#include <algorithm>
namespace lights_055 {
    struct Phase { unsigned east; unsigned west; }; // OK
    static float clampf(float v){ return std::max(0.5F,std::min(2.0F,v)); }
    void schedule(){
        unsigned east=10U, west=8U;            // NC
        float bias=1.0F, step=0.0F;            // NC
        bool fog=false, night=true;            // NC
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
