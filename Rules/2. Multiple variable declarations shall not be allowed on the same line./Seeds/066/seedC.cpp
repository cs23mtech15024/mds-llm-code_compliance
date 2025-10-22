// Context: Satellite battery heater thermostat

#include <iostream>
int main(){
    double t=-5.0;        // C
    double set=0.0;       // C
    float pwr=0.0F;       // C
    float duty=0.0F;      // C
    unsigned on=0U;       // C
    unsigned trips=0U;    // C
    duty += 0.1F; t += 0.2;
    std::cout<<t<<","<<set<<","<<pwr<<","<<duty<<","<<on<<","<<trips<<"\n";
    return 0;
}
