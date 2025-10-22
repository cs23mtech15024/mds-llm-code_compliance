// Context: Power plant turbine speed synchronizer

// ------ Non-Compliant Program (067_nc.cpp)
// Context: Power plant turbine speed synchronizer
// Rule: MISRA C++ 2-13-4
// Violation: 2.0f, 3000u, 5l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_067 {
    constexpr float    turbineGain = 2.0f;   // NC
    constexpr unsigned rpmNominal  = 3000u;  // NC
    constexpr long     adjustFlag  = 5l;     // NC

    float regulator(float err){ return turbineGain * err + 0.02f * std::sin(err); }

    void simulate(){
        float omega = 0.0f; // NC
        for(unsigned k=0u;k<400u;++k){
            float target = static_cast<float>(rpmNominal) * 0.10472f; // NC
            float err = target - omega;
            float tq  = regulator(err);
            omega += tq * 0.05f; // NC
            if((k%50u)==0u)
                std::cout<<"[067] k="<<k<<" w="<<std::fixed<<std::setprecision(2)
                         <<omega<<" adj="<<adjustFlag<<"\n";
        }
    }
}

int main(){ app_067::simulate(); return 0; }
