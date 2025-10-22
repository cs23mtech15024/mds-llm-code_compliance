// Context: Autonomous submarine sonar ping scheduler

// ------ Compliant Program (043_c.cpp)
// Compliant: single declarator per declaration.
#include <iostream>
#include <vector>
#include <algorithm>
namespace sonar_043 {
    struct Plan { unsigned dt; unsigned jitter; }; // OK
    static unsigned clampu(unsigned v,unsigned lo,unsigned hi){ return std::max(lo,std::min(hi,v)); }
    void schedule(){
        unsigned interval=2U;                    // C
        unsigned jitter=1U;                      // C
        float depth=30.0F;                       // C
        float speed=2.5F;                        // C
        bool mute=false;                         // C
        bool armed=true;                         // C
        Plan p{interval,jitter};
        std::vector<unsigned> slots;
        for (unsigned t=0U;t<20U;t+=interval){
            unsigned d = clampu(t + (t%2U?jitter:0U), 1U, 25U);
            if (!mute){ slots.push_back(d); }
            if ((t%6U)==0U){ armed = !armed; }
            if ((t%4U)==0U){ std::cout<<"t="<<t<<" slot="<<d<<" armed="<<armed<<"\n"; }
        }
        std::cout<<"count="<<slots.size()<<" mute="<<mute<<"\n";
    }
}
int main(){ sonar_043::schedule(); return 0; }
