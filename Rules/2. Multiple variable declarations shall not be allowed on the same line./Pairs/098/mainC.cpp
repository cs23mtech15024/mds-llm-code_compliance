// Context: Harbor tide-compensated mooring tensioner

// ------ Compliant Program (098_c.cpp)
// Compliant: one declarator per declaration throughout the file.
#include <iostream>
#include <vector>
#include <algorithm>
namespace moor_098 {
    struct Line { double tide; float tension; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void tension(){
        double tide=1.2;                           // C
        double set=1.5;                            // C
        float k=0.5F;                              // C
        float tension=0.0F;                        // C
        int cycles=0;                               // C
        int trips=0;                                // C
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
