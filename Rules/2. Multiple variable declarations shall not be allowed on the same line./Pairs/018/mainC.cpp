// Context: Robotic welder seam tracker

// ------ Compliant Program (018_c.cpp)
// Compliant rewrite with one declarator per declaration.
#include <iostream>
#include <vector>
#include <cmath>
namespace weld_018 {
    struct Sample { float off; float spd; }; // OK
    static float absf(float v){ return v<0.0F?-v:v; }
    void track(){
        float offset=0.0F;                    // C
        float speed=0.0F;                     // C
        double kp=0.6;                         // C
        double ki=0.02;                        // C
        int good=0;                            // C
        int bad=0;                             // C
        std::vector<float> seam{0.05F, -0.02F, 0.08F, 0.01F};
        for (std::size_t i=0;i<seam.size();++i){
            offset = seam[i];
            speed  = 0.8F + static_cast<float>(kp)*offset;
            if (absf(offset)<0.06F){ good++; } else { bad++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" off="<<offset<<" spd="<<speed<<"\n"; }
        }
        std::cout<<"good="<<good<<" bad="<<bad<<"\n";
    }
}
int main(){ weld_018::track(); return 0; }
