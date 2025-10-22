// Context: Tidal energy converter inverter control

#include <iostream>
int main(){
    double vdc=700.0;     // C
    double vac=0.0;       // C
    float kp=0.8F;        // C
    float ki=0.03F;       // C
    unsigned cycles=0U;   // C
    unsigned trips=0U;    // C
    vac += 5.0; vdc -= 2.0;
    std::cout<<vdc<<","<<vac<<","<<kp<<","<<ki<<","<<cycles<<","<<trips<<"\n";
    return 0;
}
