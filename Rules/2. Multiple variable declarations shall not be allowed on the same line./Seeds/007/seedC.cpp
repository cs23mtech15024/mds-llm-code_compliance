// Context: Smart thermostat adaptive PID

#include <iostream>
int main(){
    double kp=1.0;        // C
    double ki=0.1;        // C
    double kd=0.01;       // C
    float target=22.0F;   // C
    float room=21.5F;     // C
    bool heat=true;       // C
    bool cool=false;      // C
    std::cout<<kp+ki+kd<<","<<target-room<<","<<heat<<","<<cool<<"\n";
    return 0;
}
