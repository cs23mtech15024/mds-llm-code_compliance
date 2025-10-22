// Context: Autonomous submarine sonar ping scheduler

#include <iostream>
int main(){
    unsigned interval=2U, jitter=1U; // NC
    float depth=30.0F, speed=2.5F;   // NC
    bool mute=false, armed=true;     // NC
    interval+=1U; speed+=0.1F;
    std::cout<<interval<<","<<jitter<<","<<depth<<","<<speed<<","<<mute<<","<<armed<<"\n";
    return 0;
}
