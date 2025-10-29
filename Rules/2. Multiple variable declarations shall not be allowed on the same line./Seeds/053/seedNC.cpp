// Context: Neural network inference accelerator load balancer

#include <iostream>
int main(){
    float load=0.0F, thresh=0.8F;     // NC
    unsigned cores=8U, busy=3U;       // NC
    int tasks=10, queued=0;           // NC
    load += 0.2F; busy++; queued += 2;
    std::cout<<load<<","<<thresh<<","<<cores<<","<<busy<<","<<tasks<<","<<queued<<"\n";
    return 0;
}
