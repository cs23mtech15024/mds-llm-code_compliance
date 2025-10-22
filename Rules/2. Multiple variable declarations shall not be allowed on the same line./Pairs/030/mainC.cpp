// Context: Mining haul truck tire pressure monitor

// ------ Compliant Program (030_c.cpp)
// One declarator per declaration (MISRA C++ 8-0-1 compliant).
#include <iostream>
#include <array>
#include <algorithm>
namespace tire_030 {
    struct Tires { float fl; float fr; float rl; float rr; }; // OK
    static float clip(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void check(){
        float pFL=95.0F;                           // C
        float pFR=96.0F;                           // C
        float pRL=100.0F;                          // C
        float pRR=99.0F;                           // C
        unsigned faults=0U;                         // C
        unsigned warns=0U;                          // C
        Tires t{pFL,pFR,pRL,pRR};
        for (unsigned i=0U;i<6U;++i){
            t.fr -= 1.0F; t.rr -= 2.0F;
            t.fl = clip(t.fl,80.0F,110.0F); t.fr = clip(t.fr,80.0F,110.0F);
            t.rl = clip(t.rl,80.0F,110.0F); t.rr = clip(t.rr,80.0F,110.0F);
            if (t.fr<92.0F || t.rr<92.0F){ faults++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" fl="<<t.fl<<" fr="<<t.fr<<" rl="<<t.rl<<" rr="<<t.rr<<"\n"; }
        }
        std::cout<<"faults="<<faults<<" warns="<<warns<<"\n";
    }
}
int main(){ tire_030::check(); return 0; }
