// Context: Coal plant boiler feedwater control

#include <iostream>
int main(){
    double lvl=50.0, sp=55.0;        // NC
    float kp=1.1F, ki=0.04F;         // NC
    int opens=0, closes=0;           // NC
    lvl += 0.3; opens++;
    std::cout<<lvl<<","<<sp<<","<<kp<<","<<ki<<","<<opens<<","<<closes<<"\n";
    return 0;
}
