// Context: Industrial robot torque observer calibrator

#include <iostream>
int main(){
    double tau=0.0, bias=0.0;       // NC
    float alpha=0.1F, beta=0.0F;    // NC
    unsigned it=0U, maxIt=4U;       // NC
    tau += 0.5; beta += 0.02F;
    std::cout<<tau<<","<<bias<<","<<alpha<<","<<beta<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
