// Context: Wind farm battery smoothing controller

#include <iostream>
int main(){
    double p=3.5, tgt=4.0;         // NC
    float soc=0.6F, rate=0.0F;     // NC
    unsigned ticks=0U, trips=0U;   // NC
    rate = 0.2F; p += 0.1; soc += 0.01F;
    std::cout<<p<<","<<tgt<<","<<soc<<","<<rate<<","<<ticks<<","<<trips<<"\n";
    return 0;
}
