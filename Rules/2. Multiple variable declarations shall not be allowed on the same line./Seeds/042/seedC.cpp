// Context: Quantum computer cryostat temperature stabilizer

#include <iostream>
int main(){
    double temp=0.015;    // C
    double target=0.010;  // C
    float gain=0.5F;      // C
    float bias=0.0F;      // C
    unsigned it=0U;       // C
    unsigned alarms=0U;   // C
    bias += 0.01F; temp -= 0.002;
    std::cout<<temp<<","<<target<<","<<gain<<","<<bias<<","<<it<<","<<alarms<<"\n";
    return 0;
}
