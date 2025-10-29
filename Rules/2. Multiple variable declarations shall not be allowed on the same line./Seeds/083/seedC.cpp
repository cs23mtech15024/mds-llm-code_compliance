// Context: Brewery fermentation temperature controller

#include <iostream>
int main(){
    float temp=18.0F;      // C
    float setpoint=18.5F;  // C
    double gravity=1.050;  // C
    double alcohol=0.0;    // C
    int days=0;            // C
    int adjustments=0;     // C
    temp += 0.1F; days++;
    std::cout<<temp<<","<<setpoint<<","<<gravity<<","<<alcohol<<","<<days<<","<<adjustments<<"\n";
    return 0;
}
