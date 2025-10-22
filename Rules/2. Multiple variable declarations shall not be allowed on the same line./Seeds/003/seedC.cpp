// Context: Medical ventilator flow estimator

#include <iostream>
int main(){
    double flow=0.0;      // C
    double pressure=0.0;  // C
    long alarms=0L;       // C
    long warnings=0L;     // C
    bool humidOn=false;   // C
    bool heaterOn=false;  // C
    std::cout<<flow<<","<<pressure<<","<<alarms<<","<<warnings<<","<<humidOn<<","<<heaterOn<<"\n";
    return 0;
}
