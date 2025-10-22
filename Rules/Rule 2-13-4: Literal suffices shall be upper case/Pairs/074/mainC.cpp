// Context: Space probe antenna pointing refinement

// ------ Compliant Program (074_c.cpp)
// Context: Space probe antenna pointing refinement
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Fix: uses 0.005F, 500U, 2033L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_074 {
    constexpr float refine = 0.005F; // C
    constexpr unsigned cycles = 500U; // C
    constexpr long epoch = 2033L; // C

    float refineStep(float err){ return err * refine; }

    void simulate(){
        float theta = 5.0F;
        for(unsigned c=0U;c<cycles;++c){
            float ref = std::sin(0.002F * static_cast<float>(c));
            float adj = refineStep(ref - theta);
            theta += adj;
            if((c%100U)==0U)
                std::cout<<"[074] c="<<c<<" θ="<<theta<<" epoch="<<epoch<<"\n";
        }
    }
}

int main(){ app_074::simulate(); return 0; }
