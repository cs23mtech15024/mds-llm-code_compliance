// Context: Aircraft yaw correction feedback loop

// ------ Non-Compliant Program (070_nc.cpp)
// Context: Aircraft yaw correction feedback loop
// Rule: MISRA C++ 2-13-4
// Violation: 0.45f, 200u, 5l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_070 {
    constexpr float    yawRate    = 0.45f; // NC
    constexpr unsigned iteration  = 200u;  // NC
    constexpr long     baseOffset = 5l;    // NC

    struct YawState { float psi; float r; };

    float loop(float ref, YawState& s){
        float e = ref - s.psi;
        float u = 0.8f * e - 0.1f * s.r; // NC
        s.r  += u * 0.02f;               // NC
        s.psi+= s.r * 0.02f;             // NC
        return u;
    }

    void run(){
        YawState s{0.0f, 0.0f};
        for(unsigned i=0u;i<iteration;++i){
            float ref = std::sin(0.01f * static_cast<float>(i)); // NC
            (void)loop(ref, s);
            if(((i+static_cast<unsigned>(baseOffset))%40u)==0u)
                std::cout<<"[070] i="<<i<<" psi="<<std::fixed<<std::setprecision(3)
                         <<s.psi<<" r="<<s.r<<"\n";
        }
    }
}

int main(){ app_070::run(); return 0; }
