// Context: Blockchain mining pool difficulty adjuster

#include <iostream>
int main(){
    double diff=1.0, rate=0.0;        // NC
    unsigned shares=0U, rejects=0U;   // NC
    float target=0.5F, window=0.0F;   // NC
    diff += 0.1; rate += 0.05; shares++;
    std::cout<<diff<<","<<rate<<","<<shares<<","<<rejects<<","<<target<<","<<window<<"\n";
    return 0;
}
