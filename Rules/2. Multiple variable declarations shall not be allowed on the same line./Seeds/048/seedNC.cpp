// Context: Mountain tunnel ventilation controller

#include <iostream>
int main(){
    float co=3.0F, nox=0.5F;         // NC
    float fan=0.0F, damper=0.0F;     // NC
    unsigned t=0U, alarms=0U;        // NC
    fan += 0.2F; damper += 0.1F;
    std::cout<<co<<","<<nox<<","<<fan<<","<<damper<<","<<t<<","<<alarms<<"\n";
    return 0;
}
