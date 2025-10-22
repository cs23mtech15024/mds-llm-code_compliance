// Context: Autonomous rail yard switch matrix arbiter

#include <iostream>
int main(){
    unsigned tracks=7U, routes=3U;  // NC
    float bias=0.0F, gain=0.6F;     // NC
    int moves=0, conflicts=0;       // NC
    bias += 0.2F; routes += 1U;
    std::cout<<tracks<<","<<routes<<","<<bias<<","<<gain<<","<<moves<<","<<conflicts<<"\n";
    return 0;
}
