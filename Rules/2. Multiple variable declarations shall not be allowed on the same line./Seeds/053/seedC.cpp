// Context: Neural network inference accelerator load balancer

#include <iostream>
int main(){
    float load=0.0F;      // C
    float thresh=0.8F;    // C
    unsigned cores=8U;    // C
    unsigned busy=3U;     // C
    int tasks=10;         // C
    int queued=0;         // C
    load += 0.2F; busy++; queued += 2;
    std::cout<<load<<","<<thresh<<","<<cores<<","<<busy<<","<<tasks<<","<<queued<<"\n";
    return 0;
}
