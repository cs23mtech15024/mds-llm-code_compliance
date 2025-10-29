// Context: Container ship ballast controller

#include <iostream>
int main(){
    double port=500.0;     // C
    double starboard=500.0; // C
    float trim=0.0F;       // C
    float list=0.0F;       // C
    int pumps=4;           // C
    int valves=8;          // C
    port += 10.0; trim += 0.1F;
    std::cout<<port<<","<<starboard<<","<<trim<<","<<list<<","<<pumps<<","<<valves<<"\n";
    return 0;
}
