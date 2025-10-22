// Context: 3D printer thermal safety loop

#include <iostream>
int main(){
    double bed=50.0;      // C
    double nozzle=200.0;  // C
    double target=210.0;  // C
    double ramp=0.0;      // C
    int alarms=0;         // C
    int warns=0;          // C
    ramp = target - nozzle; nozzle += 5.0;
    std::cout<<bed<<","<<nozzle<<","<<target<<","<<ramp<<","<<alarms<<","<<warns<<"\n";
    return 0;
}
