// Context: Autonomous forklift proximity guard

// ------ Compliant Program (023_c.cpp)
// Compliant rewrite: one declarator per declaration.
#include <iostream>
#include <cmath>
namespace prox_023 {
    struct Radar { float d; float th; }; // OK
    static float absf(float v){ return v<0.0F?-v:v; }
    void guard(){
        float dist=3.0F;                         // C
        float thresh=1.5F;                       // C
        bool slow=false;                          // C
        bool stop=false;                          // C
        unsigned events=0U;                       // C
        unsigned trips=0U;                        // C
        for (unsigned i=0U; i<8U; ++i){
            dist -= 0.4F; events++;
            slow = (dist<thresh);
            if (absf(dist)<0.2F){ stop=true; trips++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" d="<<dist<<" slow="<<slow<<" stop="<<stop<<"\n"; }
        }
        std::cout<<"events="<<events<<" trips="<<trips<<"\n";
    }
}
int main(){ prox_023::guard(); return 0; }
