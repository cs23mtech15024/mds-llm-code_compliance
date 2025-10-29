// Context: Electron microscope lens voltage controller

#include <iostream>
int main(){
    double voltage=200000.0; // C
    double current=0.0;      // C
    float focus=0.0F;        // C
    float stigX=0.0F;        // C
    float stigY=0.0F;        // C
    int images=0;            // C
    int calibrations=0;      // C
    voltage += 100.0; images++;
    std::cout<<voltage<<","<<current<<","<<focus<<","<<stigX<<","<<stigY<<","<<images<<","<<calibrations<<"\n";
    return 0;
}
