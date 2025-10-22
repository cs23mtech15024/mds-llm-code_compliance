// Context: Deep-sea ROV buoyancy trim controller

// ------ Non-Compliant Program (083_nc.cpp)
// Multi-declarator declarations (// NC) violate 8-0-1.
#include <iostream>
#include <vector>
#include <cmath>
namespace rov_083 {
    struct State { double z; float pump; float bleed; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void trim(){
        double depth=50.0, tgt=47.5;           // NC
        float pump=0.0F, bleed=0.0F;           // NC
        unsigned steps=0U, trips=0U;           // NC
        std::vector<double> sea{0.1,-0.2,0.3,-0.1,0.0,-0.3,0.2};
        for (std::size_t i=0;i<sea.size();++i){
            double e = tgt - depth;
            pump  = std::min(1.0F,std::max(0.0F,pump  + static_cast<float>(e*0.05)));
            bleed = std::min(1.0F,std::max(0.0F,bleed + static_cast<float>(-e*0.03)));
            depth = clampd(depth + sea[i] - static_cast<double>(pump)*0.6 + static_cast<double>(bleed)*0.4, 30.0, 80.0);
            if (depth<40.0 || depth>70.0){ trips++; }
            steps++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" z="<<depth<<" p="<<pump<<" b="<<bleed<<"\n"; }
        }
        std::cout<<"steps="<<steps<<" trips="<<trips<<"\n";
    }
}
int main(){ rov_083::trim(); return 0; }
