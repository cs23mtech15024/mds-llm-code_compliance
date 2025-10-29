// Context: Arctic research station power dispatcher

#include <iostream>
int main(){
    double solar=1.2, wind=2.1;       // NC
    float battery=0.6F, diesel=0.0F;  // NC
    unsigned ticks=0U, alarms=0U;     // NC
    solar += 0.1; wind -= 0.2; battery += 0.05F;
    std::cout<<solar<<","<<wind<<","<<battery<<","<<diesel<<","<<ticks<<","<<alarms<<"\n";
    return 0;
}
