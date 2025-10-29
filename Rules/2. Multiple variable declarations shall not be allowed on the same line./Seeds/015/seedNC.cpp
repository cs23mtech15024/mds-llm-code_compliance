// Context: 3D printer thermal safety loop

#include <iostream>
int main(){
    double bed=50.0, nozzle=200.0;   // NC
    double target=210.0, ramp=0.0;   // NC
    int alarms=0, warns=0;           // NC
    ramp = target - nozzle; nozzle += 5.0;
    std::cout<<bed<<","<<nozzle<<","<<target<<","<<ramp<<","<<alarms<<","<<warns<<"\n";
    return 0;
}
