// Context: Arctic research station power dispatcher

#include <iostream>
int main(){
    double solar=1.2;       // C
    double wind=2.1;        // C
    float battery=0.6F;     // C
    float diesel=0.0F;      // C
    unsigned ticks=0U;      // C
    unsigned alarms=0U;     // C
    solar += 0.1; wind -= 0.2; battery += 0.05F;
    std::cout<<solar<<","<<wind<<","<<battery<<","<<diesel<<","<<ticks<<","<<alarms<<"\n";
    return 0;
}
