// Context: Hydroelectric turbine governor loop

#include <iostream>
int main(){
    double rpm=300.0;    // C
    double set=310.0;    // C
    float kp=0.9F;       // C
    float ki=0.03F;      // C
    unsigned steps=0U;   // C
    unsigned faults=0U;  // C
    rpm += 1.0; set -= 0.5;
    std::cout<<rpm<<","<<set<<","<<kp<<","<<ki<<","<<steps<<","<<faults<<"\n";
    return 0;
}
