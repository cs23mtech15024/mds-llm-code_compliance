// Context: Autonomous car lane departure alert

// ------ Compliant Program (019_c.cpp)
// One declarator per declaration (compliant with 8-0-1).
#include <iostream>
#include <cmath>
namespace lane_019 {
    struct Sig { float lat; float yaw; }; // OK
    static float mag2(float a,float b){ return a*a+b*b; }
    void compute(){
        float lateral=0.0F;                    // C
        float yawRate=0.0F;                    // C
        unsigned frames=0U;                    // C
        unsigned alarms=0U;                    // C
        bool left=false;                       // C
        bool right=false;                      // C
        Sig s{0.0F,0.0F};
        for (unsigned i=0U;i<10U;++i){
            s.lat += 0.02F; s.yaw += 0.003F; frames++;
            if (s.lat>0.3F){ alarms++; right=true; }
            if (s.lat<-0.3F){ alarms++; left=true; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" e2="<<mag2(s.lat,s.yaw)<<"\n"; }
        }
        std::cout<<"frames="<<frames<<" alarms="<<alarms<<" L="<<left<<" R="<<right<<"\n";
    }
}
int main(){ lane_019::compute(); return 0; }
