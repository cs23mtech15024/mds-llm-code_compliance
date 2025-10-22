// Context: Autonomous rail yard switch matrix arbiter

#include <iostream>
int main(){
    unsigned tracks=7U;   // C
    unsigned routes=3U;   // C
    float bias=0.0F;      // C
    float gain=0.6F;      // C
    int moves=0;          // C
    int conflicts=0;      // C
    bias += 0.2F; routes += 1U;
    std::cout<<tracks<<","<<routes<<","<<bias<<","<<gain<<","<<moves<<","<<conflicts<<"\n";
    return 0;
}
