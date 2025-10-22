// Context: Satellite battery heater thermostat

// ------ Compliant Program (066_c.cpp)
// Compliant: each declaration has one declarator.
#include <iostream>
#include <vector>
namespace thermo_066 {
    struct Pack { double t; double set; }; // OK
    void heat(){
        double t=-5.0;                         // C
        double set=0.0;                        // C
        float pwr=0.0F;                        // C
        float duty=0.0F;                       // C
        unsigned on=0U;                         // C
        unsigned trips=0U;                      // C
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
