// Context: Wind turbine pitch controller

#include <iostream>
int main(){
    float pitch=0.0F;       // C
    float rate=0.0F;        // C
    double kp=0.8;          // C
    double kd=0.05;         // C
    unsigned it=0U;         // C
    unsigned maxIt=3U;      // C
    pitch += 0.1F; rate -= 0.02F;
    std::cout<<pitch<<","<<rate<<","<<kp<<","<<kd<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
