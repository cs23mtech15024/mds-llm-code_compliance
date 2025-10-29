// Context: Hospital HVAC surgical theater pressure control

#include <iostream>
int main(){
    double room=2.0;       // C
    double corridor=0.5;   // C
    float fan=0.0F;        // C
    float damper=0.0F;     // C
    unsigned t=0U;         // C
    unsigned alarms=0U;    // C
    fan += 0.3F; room += 0.1; corridor -= 0.05;
    std::cout<<room<<","<<corridor<<","<<fan<<","<<damper<<","<<t<<","<<alarms<<"\n";
    return 0;
}
