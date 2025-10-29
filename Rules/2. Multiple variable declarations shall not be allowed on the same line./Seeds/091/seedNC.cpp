// Context: Kiln temperature ramp scheduler

#include <iostream>
int main(){
    float temp=20.0F, target=1200.0F;     // NC
    float rampRate=5.0F, holdTime=60.0F;  // NC
    int segments=4, alarms=0;             // NC
    temp += rampRate; segments++;
    std::cout<<temp<<","<<target<<","<<rampRate<<","<<holdTime<<","<<segments<<","<<alarms<<"\n";
    return 0;
}
