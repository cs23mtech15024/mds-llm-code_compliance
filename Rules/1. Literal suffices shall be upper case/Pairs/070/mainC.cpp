// Context: Aircraft yaw correction feedback loop

// ------ Compliant Program (070_c.cpp)
// Context: Aircraft yaw correction feedback loop
// Rule: MISRA C++ 2-13-4
// Fix: 0.45F, 200U, 5L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_070 {
    constexpr float    yawRate    = 0.45F; // C
    constexpr unsigned iteration  = 200U;  // C
    constexpr long     baseOffset = 5L;    // C

    struct YawState { float psi; float r; };

    float loop(float ref, YawState& s){
        float e = ref - s.psi;
        float u = 0.8F * e - 0.1F * s.r; // C
        s.r  += u * 0.02F;               // C
        s.psi+= s.r * 0.02F;             // C
        return u;
    }

    void run(){
        YawState s{0.0F, 0.0F};
        for(unsigned i=0U;i<iteration;++i){
            float ref = std::sin(0.01F * static_cast<float>(i)); // C
            (void)loop(ref, s);
            if(((i+static_cast<unsigned>(baseOffset))%40U)==0U)
                std::cout<<"[070] i="<<i<<" psi="<<std::fixed<<std::setprecision(3)
                         <<s.psi<<" r="<<s.r<<"\n";
        }
    }
}

int main(){ app_070::run(); return 0; }
