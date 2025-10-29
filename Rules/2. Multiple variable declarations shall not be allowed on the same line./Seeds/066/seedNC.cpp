// Context: MRI scanner gradient coil driver

#include <iostream>
int main(){
    float gradX=0.0F, gradY=0.0F, gradZ=0.0F; // NC
    double current=2.5, voltage=12.0;         // NC
    int pulses=0, faults=0;                   // NC
    gradX += 0.1F; pulses++;
    std::cout<<gradX<<","<<gradY<<","<<gradZ<<","<<current<<","<<voltage<<","<<pulses<<","<<faults<<"\n";
    return 0;
}
