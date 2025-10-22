// Context: Offshore crane sway dampener

// ------ Compliant Program (053_c.cpp)
// Compliant: one declarator per declaration.
#include <iostream>
#include <cmath>
#include <vector>
namespace crane_053 {
    struct Sway { float x; float dx; }; // OK
    static float lim(float v,float m){ return std::max(-m,std::min(m,v)); }
    void damp(){
        float sway=0.0F;                         // C
        float rate=0.0F;                         // C
        float kp=0.8F;                           // C
        float kd=0.12F;                          // C
        unsigned it=0U;                          // C
        unsigned maxIt=12U;                      // C
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
