// Context: Hydroelectric turbine governor loop

#include <iostream>
int main(){
    double rpm=300.0, set=310.0;     // NC
    float kp=0.9F, ki=0.03F;         // NC
    unsigned steps=0U, faults=0U;    // NC
    rpm += 1.0; set -= 0.5;
    std::cout<<rpm<<","<<set<<","<<kp<<","<<ki<<","<<steps<<","<<faults<<"\n";
    return 0;
}
