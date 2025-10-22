// Context: Mars rover wheel torque regulator

// ------ Non-Compliant Program (069_nc.cpp)
// Context: Mars rover wheel torque regulator
// Rule: MISRA C++ 2-13-4
// Violation: 1.15f, 150u, 60l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_069 {
    constexpr float    torqueBias = 1.15f; // NC
    constexpr unsigned steps      = 150u;  // NC
    constexpr long     baseTorque = 60l;   // NC

    float torqueCmd(float slip){ return baseTorque + torqueBias*(1.0f-slip)*10.0f; }

    void run(){
        float slip=0.0f;
        for(unsigned k=0u;k<steps;++k){
            slip = 0.5f + 0.4f*std::sin(0.02f*static_cast<float>(k)); // NC
            float cmd = torqueCmd(slip);
            if((k%15u)==0u)
                std::cout<<"[069] k="<<k<<" slip="<<std::fixed<<std::setprecision(3)
                         <<slip<<" cmd="<<cmd<<"\n";
        }
    }
}

int main(){ app_069::run(); return 0; }
