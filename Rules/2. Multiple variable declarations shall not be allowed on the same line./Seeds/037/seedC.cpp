// Context: Runway lighting intensity scheduler

#include <iostream>
int main(){
    unsigned east=10U;     // C
    unsigned west=8U;      // C
    float bias=1.0F;       // C
    float step=0.0F;       // C
    bool fog=false;        // C
    bool night=true;       // C
    step = 0.1F; east+=1U;
    std::cout<<east<<","<<west<<","<<bias<<","<<step<<","<<fog<<","<<night<<"\n";
    return 0;
}
