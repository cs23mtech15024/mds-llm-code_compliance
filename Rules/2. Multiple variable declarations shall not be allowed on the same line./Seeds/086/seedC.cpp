// Context: Photovoltaic MPPT tracker

#include <iostream>
int main(){
    float voltage=48.0F;   // C
    float current=10.0F;   // C
    double power=0.0;      // C
    double efficiency=0.0; // C
    unsigned steps=0U;     // C
    unsigned cycles=0U;    // C
    voltage += 0.5F; steps++;
    std::cout<<voltage<<","<<current<<","<<power<<","<<efficiency<<","<<steps<<","<<cycles<<"\n";
    return 0;
}
