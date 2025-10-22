// Context: Robotic welder seam tracker

// ------ Non-Compliant Program (018_nc.cpp)
// Uses multiple declarators per declaration (8-0-1 violation).
#include <iostream>
#include <vector>
#include <cmath>
namespace weld_018 {
    struct Sample { float off; float spd; }; // OK
    static float absf(float v){ return v<0.0F?-v:v; }
    void track(){
        float offset=0.0F, speed=0.0F;        // NC
        double kp=0.6, ki=0.02;               // NC
        int good=0, bad=0;                    // NC
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
