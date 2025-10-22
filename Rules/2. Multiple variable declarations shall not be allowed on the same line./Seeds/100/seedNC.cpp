// Context: Urban flood pump station capacity balancer

#include <iostream>
int main(){
    double inflow=3.0, out=2.5;     // NC
    float pumpA=0.0F, pumpB=0.0F;   // NC
    unsigned steps=0U, alarms=0U;   // NC
    pumpA += 0.2F; out += 0.1; steps++;
    std::cout<<inflow<<","<<out<<","<<pumpA<<","<<pumpB<<","<<steps<<","<<alarms<<"\n";
    return 0;
}
