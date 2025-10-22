// Context: Automated dairy vacuum regulator

#include <iostream>
int main(){
    double vac=45.0;       // C
    double target=50.0;    // C
    float leak=0.0F;       // C
    float trim=0.0F;       // C
    int alarms=0;          // C
    int resets=0;          // C
    trim += 0.2F; vac += 0.5;
    std::cout<<vac<<","<<target<<","<<leak<<","<<trim<<","<<alarms<<","<<resets<<"\n";
    return 0;
}
