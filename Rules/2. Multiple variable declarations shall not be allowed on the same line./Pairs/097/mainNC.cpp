// Context: Smart prosthetic knee gait stabilizer

// ------ Non-Compliant Program (097_nc.cpp)
// Violates 8-0-1 using grouped declarators per declaration.
#include <iostream>
#include <array>
#include <cmath>
namespace knee_097 {
    struct Knee { float angle; float rate; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void stabilize(){
        float angle=0.0F, rate=0.0F;            // NC
        float target=15.0F, damp=0.2F;          // NC
        unsigned steps=0U, flags=0U;            // NC
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
