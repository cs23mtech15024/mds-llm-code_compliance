// Context: Industrial robot torque observer calibrator

#include <iostream>
int main(){
    double tau=0.0;       // C
    double bias=0.0;      // C
    float alpha=0.1F;     // C
    float beta=0.0F;      // C
    unsigned it=0U;       // C
    unsigned maxIt=4U;    // C
    tau += 0.5; beta += 0.02F;
    std::cout<<tau<<","<<bias<<","<<alpha<<","<<beta<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
