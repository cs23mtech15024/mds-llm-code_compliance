// Context: Autonomous taxi lane-merge negotiator

#include <iostream>
int main(){
    float v=12.0F;         // C
    float gap=8.0F;        // C
    float intent=0.0F;     // C
    float accel=0.0F;      // C
    unsigned tries=0U;     // C
    unsigned yield=0U;     // C
    intent = 0.6F; accel = 0.2F;
    std::cout<<v<<","<<gap<<","<<intent<<","<<accel<<","<<tries<<","<<yield<<"\n";
    return 0;
}
