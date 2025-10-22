// Context: Satellite battery heater thermostat

#include <iostream>
int main(){
    double t=-5.0, set=0.0;          // NC
    float pwr=0.0F, duty=0.0F;       // NC
    unsigned on=0U, trips=0U;        // NC
    duty += 0.1F; t += 0.2;
    std::cout<<t<<","<<set<<","<<pwr<<","<<duty<<","<<on<<","<<trips<<"\n";
    return 0;
}
