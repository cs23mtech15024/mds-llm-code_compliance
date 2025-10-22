// Context: Maritime autopilot heading hold

#include <iostream>
int main(){
    double heading=0.0, setpoint=90.0; // NC
    float kp=1.2F, ki=0.02F;          // NC
    int ticks=0, faults=0;            // NC
    heading += 1.0; setpoint -= 0.5;
    std::cout<<heading<<","<<setpoint<<","<<kp<<","<<ki<<","<<ticks<<","<<faults<<"\n";
    return 0;
}
