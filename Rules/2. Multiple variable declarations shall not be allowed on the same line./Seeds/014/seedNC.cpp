// Context: Medical syringe pump dosage loop

#include <iostream>
int main(){
    double mlPerHr=5.0, target=6.0;   // NC
    float err=0.0F, acc=0.0F;         // NC
    int alarms=0, warns=0;            // NC
    err = static_cast<float>(target-mlPerHr);
    std::cout<<mlPerHr<<","<<target<<","<<err<<","<<acc<<","<<alarms<<","<<warns<<"\n";
    return 0;
}
