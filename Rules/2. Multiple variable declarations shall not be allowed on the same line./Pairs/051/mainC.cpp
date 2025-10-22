// Context: Smart hydroponics nutrient dosing mixer

// ------ Compliant Program (051_c.cpp)
// Fix: each declaration has a single declarator (8-0-1 compliant).
#include <iostream>
#include <vector>
#include <numeric>
namespace hydro_051 {
    struct Mix { double ec; double valve; }; // OK
    static double clamp(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void run(){
        double ec=1.5;                            // C
        double target=1.8;                        // C
        float aDose=0.0F;                         // C
        float bDose=0.0F;                         // C
        unsigned cycles=0U;                       // C
        unsigned alarms=0U;                       // C
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
