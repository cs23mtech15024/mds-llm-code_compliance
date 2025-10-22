// Context: Wind turbine pitch controller

#include <iostream>
int main(){
    float pitch=0.0F, rate=0.0F;     // NC
    double kp=0.8, kd=0.05;          // NC
    unsigned it=0U, maxIt=3U;        // NC
    pitch += 0.1F; rate -= 0.02F;
    std::cout<<pitch<<","<<rate<<","<<kp<<","<<kd<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
