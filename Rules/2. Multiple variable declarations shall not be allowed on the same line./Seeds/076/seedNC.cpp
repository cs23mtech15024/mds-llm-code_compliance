// Context: Container ship ballast controller

#include <iostream>
int main(){
    double port=500.0, starboard=500.0;   // NC
    float trim=0.0F, list=0.0F;           // NC
    int pumps=4, valves=8;                // NC
    port += 10.0; trim += 0.1F;
    std::cout<<port<<","<<starboard<<","<<trim<<","<<list<<","<<pumps<<","<<valves<<"\n";
    return 0;
}
