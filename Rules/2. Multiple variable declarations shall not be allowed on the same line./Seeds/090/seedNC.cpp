// Context: Wildfire perimeter UAV mapping scheduler

#include <iostream>
int main(){
    float alt=120.0F, speed=18.0F;  // NC
    float overlap=0.7F, bias=0.0F;  // NC
    unsigned passes=0U, gaps=0U;    // NC
    speed -= 1.0F; overlap += 0.05F;
    std::cout<<alt<<","<<speed<<","<<overlap<<","<<bias<<","<<passes<<","<<gaps<<"\n";
    return 0;
}
