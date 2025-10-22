// Context: Smart dam spillway gate scheduler

// ------ Non-Compliant Program (074_nc.cpp)
// Violates 8-0-1 with grouped declarators.
#include <iostream>
#include <array>
#include <algorithm>
namespace dam_074 {
    struct Basin { double level; double set; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void schedule(){
        double level=7.2, set=6.8;             // NC
        float open=0.0F, rate=0.0F;            // NC
        int alerts=0, cycles=0;                 // NC
        std::array<double,8U> inflow{0.3,0.6,0.2,0.9,1.1,0.5,0.4,0.7};
        for (std::size_t i=0;i<inflow.size();++i){
            double err = level - set;
            rate = static_cast<float>(clampd(rate + err*0.05, 0.0, 1.0));
            open = std::min(1.0F, open + rate*0.1F);
            level = clampd(level + inflow[i] - static_cast<double>(open)*0.8, 5.5, 9.5);
            cycles++;
            if (level>9.0){ alerts++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" level="<<level<<" open="<<open<<"\n"; }
        }
        std::cout<<"alerts="<<alerts<<" cycles="<<cycles<<"\n";
    }
}
int main(){ dam_074::schedule(); return 0; }
