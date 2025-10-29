// Context: Space telescope reaction wheel balancer

#include <iostream>
int main(){
    float wx=0.0F;        // C
    float wy=0.0F;        // C
    double bias=0.0;      // C
    double set=0.02;      // C
    int alarms=0;         // C
    int resets=0;         // C
    wx+=0.01F; set+=0.001;
    std::cout<<wx<<","<<wy<<","<<bias<<","<<set<<","<<alarms<<","<<resets<<"\n";
    return 0;
}
