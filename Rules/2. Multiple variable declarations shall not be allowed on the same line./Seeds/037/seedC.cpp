// Context: Coal plant boiler feedwater control

#include <iostream>
int main(){
    double lvl=50.0;     // C
    double sp=55.0;      // C
    float kp=1.1F;       // C
    float ki=0.04F;      // C
    int opens=0;         // C
    int closes=0;        // C
    lvl += 0.3; opens++;
    std::cout<<lvl<<","<<sp<<","<<kp<<","<<ki<<","<<opens<<","<<closes<<"\n";
    return 0;
}
