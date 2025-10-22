// Context: Harbor tide-compensated mooring tensioner

// ------ Non-Compliant Program (098_nc.cpp)
// Uses grouped declarators per declaration; violates MISRA C++ 8-0-1.
#include <iostream>
#include <vector>
#include <algorithm>
namespace moor_098 {
    struct Line { double tide; float tension; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void tension(){
        double tide=1.2, set=1.5;               // NC
        float k=0.5F, tension=0.0F;             // NC
        int cycles=0, trips=0;                  // NC
        std::vector<double> t{1.1,1.3,1.6,1.8,1.4,1.2};
        for (std::size_t i=0;i<t.size();++i){
            tide = clampd(t[i], -1.0, 3.0);
            double e = set - tide;
            tension = std::min(1.0F,std::max(0.0F, tension + static_cast<float>(k*e)));
            if (tension>0.9F){ trips++; }
            cycles++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" tide="<<tide<<" T="<<tension<<"\n"; }
        }
        std::cout<<"cycles="<<cycles<<" trips="<<trips<<"\n";
    }
}
int main(){ moor_098::tension(); return 0; }
