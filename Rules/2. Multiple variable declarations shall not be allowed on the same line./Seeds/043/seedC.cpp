// Context: Blockchain mining pool difficulty adjuster

#include <iostream>
int main(){
    double diff=1.0;      // C
    double rate=0.0;      // C
    unsigned shares=0U;   // C
    unsigned rejects=0U;  // C
    float target=0.5F;    // C
    float window=0.0F;    // C
    diff += 0.1; rate += 0.05; shares++;
    std::cout<<diff<<","<<rate<<","<<shares<<","<<rejects<<","<<target<<","<<window<<"\n";
    return 0;
}
