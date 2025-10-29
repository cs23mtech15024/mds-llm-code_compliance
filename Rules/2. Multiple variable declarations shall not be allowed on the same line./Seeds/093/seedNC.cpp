// Context: Firefighting foam proportioner

#include <iostream>
int main(){
    float waterFlow=500.0F, foamRate=3.0F; // NC
    double pressure=100.0, ratio=0.03;    // NC
    unsigned nozzles=4U, alarms=0U;       // NC
    waterFlow += 10.0F; nozzles++;
    std::cout<<waterFlow<<","<<foamRate<<","<<pressure<<","<<ratio<<","<<nozzles<<","<<alarms<<"\n";
    return 0;
}
