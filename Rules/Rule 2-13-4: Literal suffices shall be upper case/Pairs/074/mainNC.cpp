// Context: Space probe antenna pointing refinement

// ------ Non-Compliant Program (074_nc.cpp)
// Context: Space probe antenna pointing refinement
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Violation: uses 0.005f, 500u, 2033l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_074 {
    constexpr float refine = 0.005f; // NC
    constexpr unsigned cycles = 500u; // NC
    constexpr long epoch = 2033l; // NC

    float refineStep(float err){ return err * refine; }

    void simulate(){
        float theta = 5.0f;
        for(unsigned c=0u;c<cycles;++c){
            float ref = std::sin(0.002f * static_cast<float>(c));
            float adj = refineStep(ref - theta);
            theta += adj;
            if((c%100u)==0u)
                std::cout<<"[074] c="<<c<<" θ="<<theta<<" epoch="<<epoch<<"\n";
        }
    }
}

int main(){ app_074::simulate(); return 0; }
