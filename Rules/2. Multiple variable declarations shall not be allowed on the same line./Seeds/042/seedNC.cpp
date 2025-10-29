// Context: Quantum computer cryostat temperature stabilizer

#include <iostream>
int main(){
    double temp=0.015, target=0.010;  // NC
    float gain=0.5F, bias=0.0F;       // NC
    unsigned it=0U, alarms=0U;        // NC
    bias += 0.01F; temp -= 0.002;
    std::cout<<temp<<","<<target<<","<<gain<<","<<bias<<","<<it<<","<<alarms<<"\n";
    return 0;
}
