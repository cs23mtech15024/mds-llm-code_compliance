// Context: Offshore crane sway dampener

#include <iostream>
int main(){
    float sway=0.0F;       // C
    float rate=0.0F;       // C
    float kp=0.8F;         // C
    float kd=0.12F;        // C
    unsigned it=0U;        // C
    unsigned maxIt=5U;     // C
    sway += 0.05F; rate -= 0.01F;
    std::cout<<sway<<","<<rate<<","<<kp<<","<<kd<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
