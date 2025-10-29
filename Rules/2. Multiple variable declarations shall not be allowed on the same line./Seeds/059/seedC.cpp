// Context: Subsea pipeline leak rate estimator

#include <iostream>
int main(){
    double p1=120.0;    // C
    double p2=118.5;    // C
    float rate=0.0F;    // C
    float gain=0.4F;    // C
    unsigned ticks=0U;  // C
    unsigned alarms=0U; // C
    rate += static_cast<float>((p1-p2)*0.2);
    if(rate>0.8F){ ++alarms; }
    std::cout<<p1<<","<<p2<<","<<rate<<","<<gain<<","<<ticks<<","<<alarms<<"\n";
    return 0;
}
