// Context: Rail braking cylinder pressure monitor

// ------ Compliant Program (006_c.cpp)
// Compliant: one declarator per declaration.
#include <iostream>
#include <algorithm>
#include <cstdint>
namespace rail_006 {
    struct Reading { float p; float t; }; // OK
    static float limit(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void check(){
        float p=0.0F;                   // C
        float t=0.0F;                   // C
        unsigned faults=0U;             // C
        unsigned resets=0U;             // C
        int last=-1;                    // C
        int code=0;                     // C
        Reading r{0.9F, 30.0F};
        if (r.p<0.5F){ faults++; last=100; code=1; }
        p = limit(r.p,0.0F,1.5F);
        t = limit(r.t,-10.0F,80.0F);
        if (faults>0U){ resets++; }
        std::cout<<"p="<<p<<" t="<<t<<" f="<<faults<<" r="<<resets<<" last="<<last<<" code="<<code<<"\n";
    }
}
int main(){ rail_006::check(); return 0; }
