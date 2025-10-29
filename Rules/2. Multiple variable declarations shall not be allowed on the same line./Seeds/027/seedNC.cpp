// Context: Tidal energy converter inverter control

#include <iostream>
int main(){
    double vdc=700.0, vac=0.0;      // NC
    float kp=0.8F, ki=0.03F;        // NC
    unsigned cycles=0U, trips=0U;   // NC
    vac += 5.0; vdc -= 2.0;
    std::cout<<vdc<<","<<vac<<","<<kp<<","<<ki<<","<<cycles<<","<<trips<<"\n";
    return 0;
}
