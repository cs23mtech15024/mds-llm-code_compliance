// Context: Smart grid feeder balancing

#include <iostream>
int main(){
    double phaseA=230.0, phaseB=231.0; // NC
    double phaseC=229.5, total=0.0;    // NC
    int taps=0, changes=0;             // NC
    total = phaseA+phaseB+phaseC;
    std::cout<<total<<","<<taps<<","<<changes<<"\n";
    return 0;
}
