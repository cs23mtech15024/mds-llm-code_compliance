// Context: Planetary habitat thermal radiator manager

// ------ Non-Compliant Program (080_nc.cpp)
// Groups multiple declarators per declaration — violates 8-0-1.
#include <iostream>
#include <vector>
#include <cmath>
namespace habitat_080 {
    struct Loop { double temp; double tgt; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void manage(){
        double temp=290.0, tgt=295.0;          // NC
        float pump=0.0F, valve=0.0F;           // NC
        unsigned cycles=0U, trips=0U;          // NC
        std::vector<double> heat{3.0,2.0,-1.0,0.5,-0.5,1.5};
        for (std::size_t i=0;i<heat.size();++i){
            double e = tgt - temp;
            valve = std::min(1.0F,std::max(0.0F, valve + static_cast<float>(e*0.01)));
            pump  = std::min(1.0F,std::max(0.0F, pump  + static_cast<float>(e*0.02)));
            temp  = clampd(temp + heat[i] - static_cast<double>(pump)*1.2 - static_cast<double>(valve)*0.8, 280.0, 305.0);
            if (temp>303.0 || temp<283.0){ trips++; }
            cycles++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" T="<<temp<<" p="<<pump<<" v="<<valve<<"\n"; }
        }
        std::cout<<"cycles="<<cycles<<" trips="<<trips<<"\n";
    }
}
int main(){ habitat_080::manage(); return 0; }
