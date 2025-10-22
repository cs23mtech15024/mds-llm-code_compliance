// Context: Offshore crane sway dampener

#include <iostream>
int main(){
    float sway=0.0F, rate=0.0F;      // NC
    float kp=0.8F, kd=0.12F;         // NC
    unsigned it=0U, maxIt=5U;        // NC
    sway += 0.05F; rate -= 0.01F;
    std::cout<<sway<<","<<rate<<","<<kp<<","<<kd<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
