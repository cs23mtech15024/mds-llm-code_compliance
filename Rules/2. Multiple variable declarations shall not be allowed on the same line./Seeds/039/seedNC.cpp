// Context: High-altitude balloon ballast vent control

#include <iostream>
int main(){
    double alt=10000.0, target=12000.0; // NC
    float valve=0.0F, leak=0.0F;        // NC
    unsigned ticks=0U, dumps=0U;        // NC
    valve += 0.1F; alt += 50.0;
    std::cout<<alt<<","<<target<<","<<valve<<","<<leak<<","<<ticks<<","<<dumps<<"\n";
    return 0;
}
