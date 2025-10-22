// Context: Mining haul truck tire pressure monitor

// ------ Non-Compliant Program (030_nc.cpp)
// Groups declarators in one declaration (8-0-1 violation).
#include <iostream>
#include <array>
#include <algorithm>
namespace tire_030 {
    struct Tires { float fl; float fr; float rl; float rr; }; // OK
    static float clip(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void check(){
        float pFL=95.0F, pFR=96.0F;             // NC
        float pRL=100.0F, pRR=99.0F;            // NC
        unsigned faults=0U, warns=0U;           // NC
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
