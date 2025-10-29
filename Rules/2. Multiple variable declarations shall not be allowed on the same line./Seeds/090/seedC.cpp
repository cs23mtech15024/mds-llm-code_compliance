// Context: Planetarium projector star field renderer

#include <iostream>
int main(){
    double ra=12.5;                // C
    double dec=45.0;               // C
    float magnitude=2.5F;          // C
    float color=0.5F;              // C
    unsigned stars=5000U;          // C
    unsigned constellations=88U;   // C
    ra += 0.01; stars++;
    std::cout<<ra<<","<<dec<<","<<magnitude<<","<<color<<","<<stars<<","<<constellations<<"\n";
    return 0;
}
