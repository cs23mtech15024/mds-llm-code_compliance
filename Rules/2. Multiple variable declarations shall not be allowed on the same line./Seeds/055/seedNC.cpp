// Context: Runway lighting intensity scheduler

#include <iostream>
int main(){
    unsigned east=10U, west=8U;      // NC
    float bias=1.0F, step=0.0F;      // NC
    bool fog=false, night=true;      // NC
    step = 0.1F; east+=1U;
    std::cout<<east<<","<<west<<","<<bias<<","<<step<<","<<fog<<","<<night<<"\n";
    return 0;
}
