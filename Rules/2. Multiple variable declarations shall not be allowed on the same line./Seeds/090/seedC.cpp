// Context: Wildfire perimeter UAV mapping scheduler

#include <iostream>
int main(){
    float alt=120.0F;     // C
    float speed=18.0F;    // C
    float overlap=0.7F;   // C
    float bias=0.0F;      // C
    unsigned passes=0U;   // C
    unsigned gaps=0U;     // C
    speed -= 1.0F; overlap += 0.05F;
    std::cout<<alt<<","<<speed<<","<<overlap<<","<<bias<<","<<passes<<","<<gaps<<"\n";
    return 0;
}
