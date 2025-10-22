// Context: Smart prosthetic knee gait stabilizer

// ------ Compliant Program (097_c.cpp)
// Compliant: single-declarator declarations across the file.
#include <iostream>
#include <array>
#include <cmath>
namespace knee_097 {
    struct Knee { float angle; float rate; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void stabilize(){
        float angle=0.0F;                         // C
        float rate=0.0F;                          // C
        float target=15.0F;                       // C
        float damp=0.2F;                          // C
        unsigned steps=0U;                        // C
        unsigned flags=0U;                        // C
        std::array<float,10U> imu{1.1F,0.7F,-0.2F,0.9F,1.4F,-0.5F,0.3F,1.0F,0.6F,-0.1F};
        for (std::size_t i=0;i<imu.size();++i){
            float e = target - angle;
            rate  = clampf(rate + 0.3F*e - 0.1F*damp, -4.0F, 4.0F);
            angle = clampf(angle + 0.5F*rate + 0.2F*imu[i], -30.0F, 45.0F);
            if (std::fabs(rate)>3.5F){ ++flags; }
            ++steps;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" ang="<<angle<<" rate="<<rate<<"\n"; }
        }
        std::cout<<"steps="<<steps<<" flags="<<flags<<"\n";
    }
}
int main(){ knee_097::stabilize(); return 0; }
