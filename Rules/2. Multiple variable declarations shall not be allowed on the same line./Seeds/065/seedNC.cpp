// Context: Autonomous taxi lane-merge negotiator

#include <iostream>
int main(){
    float v=12.0F, gap=8.0F;         // NC
    float intent=0.0F, accel=0.0F;    // NC
    unsigned tries=0U, yield=0U;      // NC
    intent = 0.6F; accel = 0.2F;
    std::cout<<v<<","<<gap<<","<<intent<<","<<accel<<","<<tries<<","<<yield<<"\n";
    return 0;
}
