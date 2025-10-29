// Context: Planetarium projector star field renderer

#include <iostream>
int main(){
    double ra=12.5, dec=45.0;             // NC
    float magnitude=2.5F, color=0.5F;     // NC
    unsigned stars=5000U, constellations=88U; // NC
    ra += 0.01; stars++;
    std::cout<<ra<<","<<dec<<","<<magnitude<<","<<color<<","<<stars<<","<<constellations<<"\n";
    return 0;
}
