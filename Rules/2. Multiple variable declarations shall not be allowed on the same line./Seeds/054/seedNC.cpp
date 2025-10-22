// Context: Automated dairy vacuum regulator

#include <iostream>
int main(){
    double vac=45.0, target=50.0;    // NC
    float leak=0.0F, trim=0.0F;      // NC
    int alarms=0, resets=0;          // NC
    trim += 0.2F; vac += 0.5;
    std::cout<<vac<<","<<target<<","<<leak<<","<<trim<<","<<alarms<<","<<resets<<"\n";
    return 0;
}
