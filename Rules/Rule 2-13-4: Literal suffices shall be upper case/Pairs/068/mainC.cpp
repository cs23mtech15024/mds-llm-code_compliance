// Context: Railgun capacitor charge timing circuit

// ------ Compliant Program (068_c.cpp)
// Context: Railgun capacitor charge timing circuit
// Rule: MISRA C++ 2-13-4
// Fix: 0.005F, 8U, 50L

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_068 {
    constexpr float    chargeRate     = 0.005F; // C
    constexpr unsigned capacitorCount = 8U;     // C
    constexpr long     baseTime       = 50L;    // C

    float updateV(float v){ return v + (1.0F - v) * chargeRate; }

    void simulate(){
        std::vector<float> bank(capacitorCount, 0.0F);
        for(unsigned t=0U;t<600U;++t){
            for(unsigned i=0U;i<capacitorCount;++i) bank[i]=updateV(bank[i]);
            if((t%static_cast<unsigned>(baseTime))==0U)
                std::cout<<"[068] t="<<t<<" V0="<<std::fixed<<std::setprecision(3)
                         <<bank[0]<<" Vn="<<bank.back()<<"\n";
        }
    }
}

int main(){ app_068::simulate(); return 0; }
