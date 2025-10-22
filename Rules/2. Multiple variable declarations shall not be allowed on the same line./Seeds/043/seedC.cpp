// Context: Autonomous submarine sonar ping scheduler

#include <iostream>
int main(){
    unsigned interval=2U; // C
    unsigned jitter=1U;   // C
    float depth=30.0F;    // C
    float speed=2.5F;     // C
    bool mute=false;      // C
    bool armed=true;      // C
    interval+=1U; speed+=0.1F;
    std::cout<<interval<<","<<jitter<<","<<depth<<","<<speed<<","<<mute<<","<<armed<<"\n";
    return 0;
}
