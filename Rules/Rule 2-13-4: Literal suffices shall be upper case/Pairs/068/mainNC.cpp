// Context: Railgun capacitor charge timing circuit

// ------ Non-Compliant Program (068_nc.cpp)
// Context: Railgun capacitor charge timing circuit
// Rule: MISRA C++ 2-13-4
// Violation: 0.005f, 8u, 50l

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_068 {
    constexpr float    chargeRate     = 0.005f; // NC
    constexpr unsigned capacitorCount = 8u;     // NC
    constexpr long     baseTime       = 50l;    // NC

    float updateV(float v){ return v + (1.0f - v) * chargeRate; }

    void simulate(){
        std::vector<float> bank(capacitorCount, 0.0f);
        for(unsigned t=0u;t<600u;++t){
            for(unsigned i=0u;i<capacitorCount;++i) bank[i]=updateV(bank[i]);
            if((t%static_cast<unsigned>(baseTime))==0u)
                std::cout<<"[068] t="<<t<<" V0="<<std::fixed<<std::setprecision(3)
                         <<bank[0]<<" Vn="<<bank.back()<<"\n";
        }
    }
}

int main(){ app_068::simulate(); return 0; }
