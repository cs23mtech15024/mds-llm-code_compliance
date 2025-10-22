// Context: Smart thermostat adaptive PID

#include <iostream>
int main(){
    double kp=1.0, ki=0.1, kd=0.01; // NC
    float target=22.0F, room=21.5F; // NC
    bool heat=true, cool=false;     // NC
    std::cout<<kp+ki+kd<<","<<target-room<<","<<heat<<","<<cool<<"\n";
    return 0;
}
