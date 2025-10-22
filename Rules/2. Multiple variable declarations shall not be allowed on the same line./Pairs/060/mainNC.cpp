// Context: High-altitude balloon ballast vent control

// ------ Non-Compliant Program (060_nc.cpp)
// Groups declarators; violates MISRA C++ 8-0-1.
#include <iostream>
#include <vector>
#include <algorithm>
namespace hab_060 {
    struct Env { double alt; double tgt; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void ascend(){
        double alt=10000.0, target=12000.0;    // NC
        float valve=0.0F, leak=0.0F;           // NC
        unsigned ticks=0U, dumps=0U;           // NC
        Env e{alt,target};
        for (unsigned k=0U;k<14U;++k){
            double eAlt = e.tgt - e.alt;
            valve = static_cast<float>(clampd(valve + eAlt*0.0005, 0.0, 1.0));
            e.alt = clampd(e.alt + 50.0 + static_cast<double>(valve)*30.0 - static_cast<double>(leak)*10.0, 0.0, 30000.0);
            if (eAlt<100.0 && valve>0.8F){ dumps++; valve=0.2F; }
            ticks++;
            if ((k%2U)==0U){ std::cout<<"k="<<k<<" alt="<<e.alt<<" v="<<valve<<"\n"; }
        }
        std::cout<<"ticks="<<ticks<<" dumps="<<dumps<<"\n";
    }
}
int main(){ hab_060::ascend(); return 0; }
