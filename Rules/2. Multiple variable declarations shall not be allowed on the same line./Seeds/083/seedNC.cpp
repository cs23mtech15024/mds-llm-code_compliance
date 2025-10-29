// Context: Brewery fermentation temperature controller

#include <iostream>
int main(){
    float temp=18.0F, setpoint=18.5F;     // NC
    double gravity=1.050, alcohol=0.0;    // NC
    int days=0, adjustments=0;            // NC
    temp += 0.1F; days++;
    std::cout<<temp<<","<<setpoint<<","<<gravity<<","<<alcohol<<","<<days<<","<<adjustments<<"\n";
    return 0;
}
