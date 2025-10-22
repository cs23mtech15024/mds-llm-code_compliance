// Context: Rail braking cylinder pressure monitor

#include <iostream>
int main(){
    float p=0.0F, t=0.0F;      // NC
    unsigned faults=0U, resets=0U; // NC
    int last=-1, code=0;       // NC
    std::cout<<p<<","<<t<<","<<faults<<","<<resets<<","<<last<<","<<code<<"\n";
    return 0;
}
