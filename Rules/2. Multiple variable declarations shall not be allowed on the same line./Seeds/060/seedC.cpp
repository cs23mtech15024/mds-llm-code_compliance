// Context: High-altitude balloon ballast vent control

#include <iostream>
int main(){
    double alt=10000.0;    // C
    double target=12000.0; // C
    float valve=0.0F;      // C
    float leak=0.0F;       // C
    unsigned ticks=0U;     // C
    unsigned dumps=0U;     // C
    valve += 0.1F; alt += 50.0;
    std::cout<<alt<<","<<target<<","<<valve<<","<<leak<<","<<ticks<<","<<dumps<<"\n";
    return 0;
}
