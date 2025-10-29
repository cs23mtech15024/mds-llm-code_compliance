// Context: Insulin pump bolus calculator

#include <iostream>
int main(){
    float glucose=120.0F, target=100.0F;  // NC
    float bolus=0.0F, basal=1.0F;         // NC
    int deliveries=0, warnings=0;         // NC
    bolus += 0.5F; deliveries++;
    std::cout<<glucose<<","<<target<<","<<bolus<<","<<basal<<","<<deliveries<<","<<warnings<<"\n";
    return 0;
}
