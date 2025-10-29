// Context: Cyclotron RF cavity tuner

#include <iostream>
int main(){
    double freq=28.0, voltage=50000.0;    // NC
    float phase=0.0F, power=0.0F;         // NC
    unsigned cycles=0U, faults=0U;        // NC
    freq += 0.001; cycles++;
    std::cout<<freq<<","<<voltage<<","<<phase<<","<<power<<","<<cycles<<","<<faults<<"\n";
    return 0;
}
