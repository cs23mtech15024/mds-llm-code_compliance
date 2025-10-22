// Context: Maritime autopilot heading hold

#include <iostream>
int main(){
    double heading=0.0;     // C
    double setpoint=90.0;   // C
    float kp=1.2F;          // C
    float ki=0.02F;         // C
    int ticks=0;            // C
    int faults=0;           // C
    heading += 1.0; setpoint -= 0.5;
    std::cout<<heading<<","<<setpoint<<","<<kp<<","<<ki<<","<<ticks<<","<<faults<<"\n";
    return 0;
}
