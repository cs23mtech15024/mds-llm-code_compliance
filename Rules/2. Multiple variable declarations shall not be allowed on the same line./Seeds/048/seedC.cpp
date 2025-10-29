// Context: Mountain tunnel ventilation controller

#include <iostream>
int main(){
    float co=3.0F;        // C
    float nox=0.5F;       // C
    float fan=0.0F;       // C
    float damper=0.0F;    // C
    unsigned t=0U;        // C
    unsigned alarms=0U;   // C
    fan += 0.2F; damper += 0.1F;
    std::cout<<co<<","<<nox<<","<<fan<<","<<damper<<","<<t<<","<<alarms<<"\n";
    return 0;
}
