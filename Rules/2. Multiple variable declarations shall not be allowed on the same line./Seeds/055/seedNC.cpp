// Context: Hospital HVAC surgical theater pressure control

#include <iostream>
int main(){
    double room=2.0, corridor=0.5;  // NC
    float fan=0.0F, damper=0.0F;    // NC
    unsigned t=0U, alarms=0U;       // NC
    fan += 0.3F; room += 0.1; corridor -= 0.05;
    std::cout<<room<<","<<corridor<<","<<fan<<","<<damper<<","<<t<<","<<alarms<<"\n";
    return 0;
}
