// Context: Space telescope reaction wheel balancer

#include <iostream>
int main(){
    float wx=0.0F, wy=0.0F;         // NC
    double bias=0.0, set=0.02;      // NC
    int alarms=0, resets=0;         // NC
    wx+=0.01F; set+=0.001;
    std::cout<<wx<<","<<wy<<","<<bias<<","<<set<<","<<alarms<<","<<resets<<"\n";
    return 0;
}
