// Context: Microgrid state-of-charge estimator

#include <iostream>
int main(){
    double soc=0.55, target=0.60;    // NC
    float eta=0.95F, loss=0.0F;      // NC
    unsigned it=0U, maxIt=4U;        // NC
    soc += 0.01; loss += 0.001F;
    std::cout<<soc<<","<<target<<","<<eta<<","<<loss<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
