// Context: Smart hydroponics nutrient dosing mixer

// ------ Non-Compliant Program (051_nc.cpp)
// Rule: MISRA C++ 8-0-1 — one declarator per declaration required.
// This file intentionally groups declarators (// NC) to demonstrate violations.
#include <iostream>
#include <vector>
#include <numeric>
namespace hydro_051 {
    struct Mix { double ec; double valve; }; // OK: distinct members
    static double clamp(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void run(){
        double ec=1.5, target=1.8;              // NC
        float aDose=0.0F, bDose=0.0F;           // NC
        unsigned cycles=0U, alarms=0U;          // NC
        Mix m{ec,0.0};
        std::vector<double> log;
        for (unsigned i=0U;i<12U;++i){
            double err = target - m.ec;
            float uA = static_cast<float>(clamp(err*0.6, -0.1, 0.1));
            float uB = static_cast<float>(clamp(err*0.3, -0.1, 0.1));
            aDose += uA; bDose += uB; m.ec = clamp(m.ec + uA + uB, 0.8, 2.2);
            log.push_back(m.ec); cycles++;
            if (m.ec<1.0 || m.ec>2.1){ alarms++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" ec="<<m.ec<<" a="<<aDose<<" b="<<bDose<<"\n"; }
        }
        std::cout<<"cycles="<<cycles<<" alarms="<<alarms<<" ec_mean="<<mean(log)<<"\n";
    }
}
int main(){ hydro_051::run(); return 0; }
