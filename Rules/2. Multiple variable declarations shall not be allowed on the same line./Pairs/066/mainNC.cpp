// Context: Satellite battery heater thermostat

// ------ Non-Compliant Program (066_nc.cpp)
// Uses grouped declarators; violates MISRA C++ 8-0-1.
#include <iostream>
#include <vector>
namespace thermo_066 {
    struct Pack { double t; double set; }; // OK
    void heat(){
        double t=-5.0, set=0.0;                // NC
        float pwr=0.0F, duty=0.0F;             // NC
        unsigned on=0U, trips=0U;              // NC
        Pack p{t,set};
        for (int k=0;k<16;++k){
            double e = p.set - p.t;
            duty = std::min(1.0F,std::max(0.0F,duty + static_cast<float>(e*0.05)));
            p.t += static_cast<double>(duty)*0.5 - 0.1;
            if (p.t<-10.0){ trips++; }
            if (duty>0.0F){ on++; }
            if ((k%2)==0){ std::cout<<"k="<<k<<" t="<<p.t<<" duty="<<duty<<"\n"; }
        }
        std::cout<<"on="<<on<<" trips="<<trips<<"\n";
    }
}
int main(){ thermo_066::heat(); return 0; }
