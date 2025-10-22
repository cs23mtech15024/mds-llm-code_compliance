// Context: Wildfire perimeter UAV mapping scheduler

// ------ Compliant Program (090_c.cpp)
// Compliant: single-declarator declarations throughout.
#include <iostream>
#include <deque>
#include <algorithm>
namespace fire_090 {
    struct Pass { float alt; float speed; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void schedule(){
        float alt=120.0F;                         // C
        float speed=18.0F;                        // C
        float overlap=0.7F;                       // C
        float bias=0.0F;                          // C
        unsigned passes=0U;                       // C
        unsigned gaps=0U;                          // C
        std::deque<float> wind{0.3F,-0.2F,0.1F,0.4F,-0.1F};
        for (std::size_t i=0;i<wind.size();++i){
            speed = clampf(speed + wind[i], 10.0F, 25.0F);
            overlap = clampf(overlap + (speed<15.0F?0.05F:-0.03F), 0.6F, 0.9F);
            if (overlap<0.65F){ ++gaps; }
            ++passes;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" alt="<<alt<<" sp="<<speed<<" ov="<<overlap<<"\n"; }
        }
        std::cout<<"passes="<<passes<<" gaps="<<gaps<<"\n";
    }
}
int main(){ fire_090::schedule(); return 0; }
