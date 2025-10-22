// Context: Autonomous mower boundary tracker

// ------ Non-Compliant Program (038_nc.cpp)
// Uses multiple declarators in one declaration (violates 8-0-1).
#include <iostream>
#include <cmath>
namespace mow_038 {
    struct Pose { float n; float e; }; // OK
    static float dist2(float a,float b){ return a*a+b*b; }
    void track(){
        float north=0.0F, east=0.0F;           // NC
        float speed=0.5F, turn=0.0F;           // NC
        unsigned hits=0U, warns=0U;            // NC
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
