// Context: Urban flood pump station capacity balancer

#include <iostream>
int main(){
    double inflow=3.0;    // C
    double out=2.5;       // C
    float pumpA=0.0F;     // C
    float pumpB=0.0F;     // C
    unsigned steps=0U;    // C
    unsigned alarms=0U;   // C
    pumpA += 0.2F; out += 0.1; steps++;
    std::cout<<inflow<<","<<out<<","<<pumpA<<","<<pumpB<<","<<steps<<","<<alarms<<"\n";
    return 0;
}
