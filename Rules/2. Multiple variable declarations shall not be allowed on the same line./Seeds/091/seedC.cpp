// Context: Kiln temperature ramp scheduler

#include <iostream>
int main(){
    float temp=20.0F;          // C
    float target=1200.0F;      // C
    float rampRate=5.0F;       // C
    float holdTime=60.0F;      // C
    int segments=4;            // C
    int alarms=0;              // C
    temp += rampRate; segments++;
    std::cout<<temp<<","<<target<<","<<rampRate<<","<<holdTime<<","<<segments<<","<<alarms<<"\n";
    return 0;
}
