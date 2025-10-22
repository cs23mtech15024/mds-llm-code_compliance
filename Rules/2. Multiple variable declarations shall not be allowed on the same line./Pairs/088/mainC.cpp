// Context: Data center hot-aisle containment fan control

// ------ Compliant Program (088_c.cpp)
// Compliant: one declarator per declaration across the file.
#include <iostream>
#include <vector>
#include <algorithm>
namespace dc_088 {
    struct Air { double tin; double tout; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void control(){
        double tin=28.0;                         // C
        double tout=32.0;                        // C
        float fan=0.0F;                           // C
        float damper=0.0F;                        // C
        unsigned steps=0U;                        // C
        unsigned trips=0U;                        // C
        std::vector<double> heat{1.0,0.5,-0.2,1.2,0.3,-0.5,0.8};
        for (std::size_t i=0;i<heat.size();++i){
            double e = 29.0 - tin;
            fan = std::min(1.0F,std::max(0.0F, fan + static_cast<float>(e*0.1)));
            damper = std::min(1.0F,std::max(0.0F, damper + static_cast<float>((tin-tout)*0.05)));
            tin  = clampd(tin + heat[i] - static_cast<double>(fan)*0.8, 24.0, 34.0);
            tout = clampd(tout + 0.4 - static_cast<double>(damper)*0.6, 22.0, 35.0);
            if (tin>33.0){ trips++; }
            steps++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" tin="<<tin<<" fan="<<fan<<" d="<<damper<<"\n"; }
        }
        std::cout<<"steps="<<steps<<" trips="<<trips<<"\n";
    }
}
int main(){ dc_088::control(); return 0; }
