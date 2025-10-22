// Context: Autonomous taxi lane-merge negotiator

// ------ Non-Compliant Program (065_nc.cpp)
// Multi-declarator declarations are marked // NC (violates 8-0-1).
#include <iostream>
#include <deque>
#include <algorithm>
namespace merge_065 {
    struct Ego { float v; float gap; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void negotiate(){
        float v=12.0F, gap=8.0F;                 // NC
        float intent=0.0F, accel=0.0F;           // NC
        unsigned tries=0U, yield=0U;             // NC
        std::deque<float> upstream{7.0F,8.2F,6.5F,9.0F};
        for (std::size_t i=0;i<upstream.size();++i){
            float lead = upstream[i];
            gap = clampf(gap + (lead-8.0F)*0.2F, 3.0F, 20.0F);
            intent = clampf(intent + (gap>6.0F?0.2F:-0.1F), 0.0F, 1.0F);
            accel = clampf(accel + (intent-0.5F)*0.3F, -1.0F, 1.0F);
            v = clampf(v + accel, 0.0F, 25.0F); tries++;
            if (intent>0.8F){ yield++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" v="<<v<<" gap="<<gap<<" intent="<<intent<<"\n"; }
        }
        std::cout<<"tries="<<tries<<" yield="<<yield<<"\n";
    }
}
int main(){ merge_065::negotiate(); return 0; }
