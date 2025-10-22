// Context: Wildfire perimeter UAV mapping scheduler

// ------ Non-Compliant Program (090_nc.cpp)
// Multiple declarators per declaration (// NC) — violates 8-0-1.
#include <iostream>
#include <deque>
#include <algorithm>
namespace fire_090 {
    struct Pass { float alt; float speed; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void schedule(){
        float alt=120.0F, speed=18.0F;         // NC
        float overlap=0.7F, bias=0.0F;         // NC
        unsigned passes=0U, gaps=0U;           // NC
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
