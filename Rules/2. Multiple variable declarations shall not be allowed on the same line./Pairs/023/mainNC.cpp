// Context: Autonomous forklift proximity guard

// ------ Non-Compliant Program (023_nc.cpp)
// Intentionally breaks 8-0-1 via multiple declarators per declaration.
#include <iostream>
#include <cmath>
namespace prox_023 {
    struct Radar { float d; float th; }; // OK
    static float absf(float v){ return v<0.0F?-v:v; }
    void guard(){
        float dist=3.0F, thresh=1.5F;          // NC
        bool slow=false, stop=false;           // NC
        unsigned events=0U, trips=0U;          // NC
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
