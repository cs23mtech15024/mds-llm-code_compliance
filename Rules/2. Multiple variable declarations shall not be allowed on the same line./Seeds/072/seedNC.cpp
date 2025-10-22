// Context: Autonomous warehouse shuttle traffic coordinator

#include <iostream>
int main(){
    unsigned lanes=4U, docks=6U;      // NC
    float bias=0.0F, gain=0.5F;       // NC
    int reroutes=0, stalls=0;         // NC
    bias += 0.1F; lanes += 1U;
    std::cout<<lanes<<","<<docks<<","<<bias<<","<<gain<<","<<reroutes<<","<<stalls<<"\n";
    return 0;
}
