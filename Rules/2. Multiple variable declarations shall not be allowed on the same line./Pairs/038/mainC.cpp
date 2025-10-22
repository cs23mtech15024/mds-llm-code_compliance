// Context: Autonomous mower boundary tracker

// ------ Compliant Program (038_c.cpp)
// Compliant: one declarator per declaration.
#include <iostream>
#include <cmath>
namespace mow_038 {
    struct Pose { float n; float e; }; // OK
    static float dist2(float a,float b){ return a*a+b*b; }
    void track(){
        float north=0.0F;                          // C
        float east=0.0F;                           // C
        float speed=0.5F;                          // C
        float turn=0.0F;                           // C
        unsigned hits=0U;                           // C
        unsigned warns=0U;                          // C
        for (unsigned i=0U;i<14U;++i){
            north += 0.2F; east += 0.1F; turn = (i%2U)?0.1F:-0.1F;
            if (dist2(north,east)>25.0F){ warns++; }
            if ((i%3U)==0U){ hits++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" n="<<north<<" e="<<east<<" t="<<turn<<"\n"; }
        }
        std::cout<<"hits="<<hits<<" warns="<<warns<<"\n";
    }
}
int main(){ mow_038::track(); return 0; }
