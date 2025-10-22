// Context: Rail braking cylinder pressure monitor

#include <iostream>
int main(){
    float p=0.0F;          // C
    float t=0.0F;          // C
    unsigned faults=0U;    // C
    unsigned resets=0U;    // C
    int last=-1;           // C
    int code=0;            // C
    std::cout<<p<<","<<t<<","<<faults<<","<<resets<<","<<last<<","<<code<<"\n";
    return 0;
}
