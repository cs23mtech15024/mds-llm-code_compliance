// Context: Firefighting foam proportioner

#include <iostream>
int main(){
    float waterFlow=500.0F;    // C
    float foamRate=3.0F;       // C
    double pressure=100.0;     // C
    double ratio=0.03;         // C
    unsigned nozzles=4U;       // C
    unsigned alarms=0U;        // C
    waterFlow += 10.0F; nozzles++;
    std::cout<<waterFlow<<","<<foamRate<<","<<pressure<<","<<ratio<<","<<nozzles<<","<<alarms<<"\n";
    return 0;
}
