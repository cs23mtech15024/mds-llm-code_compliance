// Context: Subsea pipeline leak rate estimator

// ------ Non-Compliant Program (091_nc.cpp)
// Rule: MISRA C++ 8-0-1 — limit each declaration to a single declarator.
// This file intentionally groups declarators (// NC) to demonstrate violations.
#include <iostream>
#include <vector>
#include <numeric>
namespace leak_091 {
    struct Seg { double p1; double p2; }; // OK: distinct members
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    static double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void estimate(){
        double p1=120.0, p2=118.5;             // NC
        float rate=0.0F, gain=0.4F;            // NC
        unsigned ticks=0U, alarms=0U;          // NC
        std::vector<double> meas{118.7,118.3,118.0,117.8,117.6,117.5};
        for (std::size_t i=0;i<meas.size();++i){
            p2 = clampd(meas[i], 100.0, 140.0);
            double dp = p1 - p2;
            rate = std::min(2.0F, std::max(0.0F, rate + static_cast<float>(gain*dp*0.05)));
            if (rate>1.2F){ alarms++; }
            ticks++;
            p1 = clampd(p1 - 0.15, 110.0, 130.0);
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" p2="<<p2<<" rate="<<rate<<"\n"; }
        }
        std::cout<<"ticks="<<ticks<<" alarms="<<alarms<<" meanP2="<<mean(meas)<<"\n";
    }
}
int main(){ leak_091::estimate(); return 0; }
