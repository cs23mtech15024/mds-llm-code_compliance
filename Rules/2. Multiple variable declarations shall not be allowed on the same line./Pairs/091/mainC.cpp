// Context: Subsea pipeline leak rate estimator

// ------ Compliant Program (091_c.cpp)
// Fix: one declarator per declaration throughout (compliant with 8-0-1).
#include <iostream>
#include <vector>
#include <numeric>
namespace leak_091 {
    struct Seg { double p1; double p2; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    static double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void estimate(){
        double p1=120.0;                          // C
        double p2=118.5;                          // C
        float rate=0.0F;                           // C
        float gain=0.4F;                           // C
        unsigned ticks=0U;                         // C
        unsigned alarms=0U;                        // C
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
