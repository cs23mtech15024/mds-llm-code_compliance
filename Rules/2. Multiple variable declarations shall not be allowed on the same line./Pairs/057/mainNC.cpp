// Context: Solar tracker dual-axis alignment

// ------ Non-Compliant Program (057_nc.cpp)
// Multi-declarator lines cause 8-0-1 noncompliance.
#include <iostream>
#include <cmath>
namespace solar_057 {
    struct Axis { float ang; float rate; }; // OK
    static float clamp(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void align(){
        float az=0.0F, el=0.0F;                 // NC
        float azRate=0.0F, elRate=0.0F;         // NC
        unsigned faults=0U, moves=0U;           // NC
        for (unsigned k=0U;k<16U;++k){
            float eAz = 1.0F - az; float eEl = 0.6F - el;
            azRate = clamp(azRate + eAz*0.1F, -0.4F, 0.4F);
            elRate = clamp(elRate + eEl*0.1F, -0.4F, 0.4F);
            az += azRate; el += elRate; moves++;
            if (std::fabs(eAz)+std::fabs(eEl)>2.0F){ faults++; }
            if ((k%2U)==0U){ std::cout<<"k="<<k<<" az="<<az<<" el="<<el<<"\n"; }
        }
        std::cout<<"moves="<<moves<<" faults="<<faults<<"\n";
    }
}
int main(){ solar_057::align(); return 0; }
