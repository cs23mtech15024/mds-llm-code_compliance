// Context: Pipeline pressure relief supervisor

// ------ Non-Compliant Program (032_nc.cpp)
// Demonstrates 8-0-1 violations by grouping multiple declarators.
#include <iostream>
#include <algorithm>
#include <vector>
namespace pipe_032 {
    struct Gauge { float p; float limit; }; // OK
    static float clamp(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void supervise(){
        float p=55.0F, limit=60.0F;             // NC
        int warns=0, trips=0;                   // NC
        bool relieve=false, leak=false;         // NC
        Gauge g{p,limit};
        std::vector<float> shocks{2.0F,-1.0F,3.5F,0.0F,-2.0F};
        for (std::size_t i=0;i<shocks.size();++i){
            g.p = clamp(g.p + shocks[i], 0.0F, 100.0F);
            relieve = (g.p>g.limit);
            if (g.p>g.limit){ warns++; if ((i%2U)==1U){ trips++; } }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" p="<<g.p<<" lim="<<g.limit<<" rl="<<relieve<<"\n"; }
        }
        leak = (warns>3);
        std::cout<<"warns="<<warns<<" trips="<<trips<<" leak="<<leak<<"\n";
    }
}
int main(){ pipe_032::supervise(); return 0; }
