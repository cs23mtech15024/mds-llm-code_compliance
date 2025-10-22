// Context: Mars rover wheel torque regulator

// ------ Compliant Program (069_c.cpp)
// Context: Mars rover wheel torque regulator
// Rule: MISRA C++ 2-13-4
// Fix: 1.15F, 150U, 60L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_069 {
    constexpr float    torqueBias = 1.15F; // C
    constexpr unsigned steps      = 150U;  // C
    constexpr long     baseTorque = 60L;   // C

    float torqueCmd(float slip){ return baseTorque + torqueBias*(1.0F-slip)*10.0F; }

    void run(){
        float slip=0.0F;
        for(unsigned k=0U;k<steps;++k){
            slip = 0.5F + 0.4F*std::sin(0.02F*static_cast<float>(k)); // C
            float cmd = torqueCmd(slip);
            if((k%15U)==0U)
                std::cout<<"[069] k="<<k<<" slip="<<std::fixed<<std::setprecision(3)
                         <<slip<<" cmd="<<cmd<<"\n";
        }
    }
}

int main(){ app_069::run(); return 0; }
