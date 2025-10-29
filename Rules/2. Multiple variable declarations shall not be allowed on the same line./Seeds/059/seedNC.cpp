// Context: Subsea pipeline leak rate estimator

#include <iostream>
int main(){
    double p1=120.0, p2=118.5;     // NC
    float rate=0.0F, gain=0.4F;    // NC
    unsigned ticks=0U, alarms=0U;  // NC
    rate += static_cast<float>((p1-p2)*0.2);
    if(rate>0.8F){ ++alarms; }
    std::cout<<p1<<","<<p2<<","<<rate<<","<<gain<<","<<ticks<<","<<alarms<<"\n";
    return 0;
}
