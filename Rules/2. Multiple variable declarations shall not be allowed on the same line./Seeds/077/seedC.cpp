// Context: Cyclotron RF cavity tuner

#include <iostream>
int main(){
    double freq=28.0;      // C
    double voltage=50000.0; // C
    float phase=0.0F;      // C
    float power=0.0F;      // C
    unsigned cycles=0U;    // C
    unsigned faults=0U;    // C
    freq += 0.001; cycles++;
    std::cout<<freq<<","<<voltage<<","<<phase<<","<<power<<","<<cycles<<","<<faults<<"\n";
    return 0;
}
