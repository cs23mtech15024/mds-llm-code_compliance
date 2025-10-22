// Context: Power plant turbine speed synchronizer

// ------ Compliant Program (067_c.cpp)
// Context: Power plant turbine speed synchronizer
// Rule: MISRA C++ 2-13-4
// Fix: 2.0F, 3000U, 5L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_067 {
    constexpr float    turbineGain = 2.0F;   // C
    constexpr unsigned rpmNominal  = 3000U;  // C
    constexpr long     adjustFlag  = 5L;     // C

    float regulator(float err){ return turbineGain * err + 0.02F * std::sin(err); }

    void simulate(){
        float omega = 0.0F; // C
        for(unsigned k=0U;k<400U;++k){
            float target = static_cast<float>(rpmNominal) * 0.10472F; // C
            float err = target - omega;
            float tq  = regulator(err);
            omega += tq * 0.05F; // C
            if((k%50U)==0U)
                std::cout<<"[067] k="<<k<<" w="<<std::fixed<<std::setprecision(2)
                         <<omega<<" adj="<<adjustFlag<<"\n";
        }
    }
}

int main(){ app_067::simulate(); return 0; }
