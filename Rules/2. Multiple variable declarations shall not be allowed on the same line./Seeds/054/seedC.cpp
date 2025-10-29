// Context: Wind farm battery smoothing controller

#include <iostream>
int main(){
    double p=3.5;        // C
    double tgt=4.0;      // C
    float soc=0.6F;      // C
    float rate=0.0F;     // C
    unsigned ticks=0U;   // C
    unsigned trips=0U;   // C
    rate = 0.2F; p += 0.1; soc += 0.01F;
    std::cout<<p<<","<<tgt<<","<<soc<<","<<rate<<","<<ticks<<","<<trips<<"\n";
    return 0;
}
