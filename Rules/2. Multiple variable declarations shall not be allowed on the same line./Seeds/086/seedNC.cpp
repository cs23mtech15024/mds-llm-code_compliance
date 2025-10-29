// Context: Photovoltaic MPPT tracker

#include <iostream>
int main(){
    float voltage=48.0F, current=10.0F;   // NC
    double power=0.0, efficiency=0.0;     // NC
    unsigned steps=0U, cycles=0U;         // NC
    voltage += 0.5F; steps++;
    std::cout<<voltage<<","<<current<<","<<power<<","<<efficiency<<","<<steps<<","<<cycles<<"\n";
    return 0;
}
