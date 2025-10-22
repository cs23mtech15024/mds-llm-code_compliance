// Context: Data center chilled-water valve optimizer

// ------ Compliant Program (049_c.cpp)
// Compliant: declarations contain one declarator each.
#include <iostream>
#include <vector>
#include <algorithm>
namespace chill_049 {
    struct Loop { float supply; float ret; }; // OK
    static float clip(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void optimize(){
        float supply=7.0F;                       // C
        float returnT=12.0F;                     // C
        float gain=1.0F;                         // C
        float bias=0.0F;                         // C
        unsigned loops=0U;                       // C
        unsigned faults=0U;                      // C
        Loop L{supply,returnT};
        std::vector<float> loads{0.6F,0.8F,0.4F,0.7F,0.9F};
        for (std::size_t i=0;i<loads.size();++i){
            float err = loads[i]-0.7F;
            float u = gain*err + bias;
            L.supply = clip(L.supply + u, 4.0F, 12.0F);
            L.ret    = clip(L.ret    + u*0.5F, 8.0F, 16.0F);
            if (L.ret>15.0F){ faults++; }
            loops++;
            bias += 0.01F;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" sup="<<L.supply<<" ret="<<L.ret<<" u="<<u<<"\n"; }
        }
        std::cout<<"loops="<<loops<<" faults="<<faults<<"\n";
    }
}
int main(){ chill_049::optimize(); return 0; }
