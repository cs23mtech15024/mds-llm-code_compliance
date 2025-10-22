// Context: Wind turbine pitch controller

// ------ Non-Compliant Program (012_nc.cpp)
// Demonstrates 8-0-1 violations by grouping multiple declarators.
#include <iostream>
#include <vector>
#include <algorithm>
namespace wind_012 {
    struct Pitch { float deg; float rate; }; // OK
    static float clamp(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void control(){
        float pitch=0.0F, rate=0.0F;             // NC
        double kp=0.8, kd=0.05;                  // NC
        unsigned it=0U, maxIt=6U;                // NC
        Pitch p{0.0F,0.0F};
        for (; it<maxIt; ++it){
            float wind = (it%2U)?9.5F:11.0F;
            float err  = (wind>10.0F)?(wind-10.0F):0.0F;
            float u    = static_cast<float>(kp)*err - static_cast<float>(kd)*rate;
            u = clamp(u,-2.0F,2.0F);
            p.rate = u; p.deg += p.rate; rate = p.rate; pitch = p.deg;
            if ((it%3U)==0U){ std::cout<<"it="<<it<<" pitch="<<pitch<<" rate="<<rate<<"\n"; }
        }
        std::cout<<"done it="<<it<<"/"<<maxIt<<"\n";
    }
}
int main(){ wind_012::control(); return 0; }
