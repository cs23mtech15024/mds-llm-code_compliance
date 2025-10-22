// Context: Smart grid feeder balancing

#include <iostream>
int main(){
    double phaseA=230.0;  // C
    double phaseB=231.0;  // C
    double phaseC=229.5;  // C
    double total=0.0;     // C
    int taps=0;           // C
    int changes=0;        // C
    total = phaseA+phaseB+phaseC;
    std::cout<<total<<","<<taps<<","<<changes<<"\n";
    return 0;
}
