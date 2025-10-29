// Context: Microgrid state-of-charge estimator

#include <iostream>
int main(){
    double soc=0.55;      // C
    double target=0.60;   // C
    float eta=0.95F;      // C
    float loss=0.0F;      // C
    unsigned it=0U;       // C
    unsigned maxIt=4U;    // C
    soc += 0.01; loss += 0.001F;
    std::cout<<soc<<","<<target<<","<<eta<<","<<loss<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
