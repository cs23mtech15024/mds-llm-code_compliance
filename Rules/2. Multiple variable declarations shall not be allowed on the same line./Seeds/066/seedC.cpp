// Context: MRI scanner gradient coil driver

#include <iostream>
int main(){
    float gradX=0.0F;      // C
    float gradY=0.0F;      // C
    float gradZ=0.0F;      // C
    double current=2.5;    // C
    double voltage=12.0;   // C
    int pulses=0;          // C
    int faults=0;          // C
    gradX += 0.1F; pulses++;
    std::cout<<gradX<<","<<gradY<<","<<gradZ<<","<<current<<","<<voltage<<","<<pulses<<","<<faults<<"\n";
    return 0;
}
