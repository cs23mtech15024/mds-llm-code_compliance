// Context: Offshore crane sway dampener

// ------ Non-Compliant Program (053_nc.cpp)
// Intentionally groups declarators; violates rule 8-0-1.
#include <iostream>
#include <cmath>
#include <vector>
namespace crane_053 {
    struct Sway { float x; float dx; }; // OK
    static float lim(float v,float m){ return std::max(-m,std::min(m,v)); }
    void damp(){
        float sway=0.0F, rate=0.0F;            // NC
        float kp=0.8F, kd=0.12F;               // NC
        unsigned it=0U, maxIt=12U;             // NC
        Sway s{0.0F,0.0F};
        for (; it<maxIt; ++it){
            float est = s.x + 0.1F*s.dx;
            float e = -est;
            float u = lim(kp*e - kd*s.dx, 0.5F);
            s.dx += u*0.2F; s.x += s.dx;
            if ((it%3U)==0U){ std::cout<<"it="<<it<<" x="<<s.x<<" dx="<<s.dx<<" u="<<u<<"\n"; }
        }
        std::cout<<"iters="<<it<<"\n";
    }
}
int main(){ crane_053::damp(); return 0; }
