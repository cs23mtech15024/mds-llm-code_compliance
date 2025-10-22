// Context: Medical syringe pump dosage loop

#include <iostream>
int main(){
    double mlPerHr=5.0;    // C
    double target=6.0;     // C
    float err=0.0F;        // C
    float acc=0.0F;        // C
    int alarms=0;          // C
    int warns=0;           // C
    err = static_cast<float>(target-mlPerHr);
    std::cout<<mlPerHr<<","<<target<<","<<err<<","<<acc<<","<<alarms<<","<<warns<<"\n";
    return 0;
}
