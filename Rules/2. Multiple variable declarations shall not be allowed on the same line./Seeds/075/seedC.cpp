// Context: Insulin pump bolus calculator

#include <iostream>
int main(){
    float glucose=120.0F;  // C
    float target=100.0F;   // C
    float bolus=0.0F;      // C
    float basal=1.0F;      // C
    int deliveries=0;      // C
    int warnings=0;        // C
    bolus += 0.5F; deliveries++;
    std::cout<<glucose<<","<<target<<","<<bolus<<","<<basal<<","<<deliveries<<","<<warnings<<"\n";
    return 0;
}
