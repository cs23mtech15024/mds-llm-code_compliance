// Context: Dialysis machine flow regulator

#include <iostream>
int main(){
    float flowRate=200.0F, pressure=0.0F; // NC
    double volume=0.0, time=0.0;          // NC
    unsigned cycles=0U, alarms=0U;        // NC
    flowRate += 1.0F; cycles++;
    std::cout<<flowRate<<","<<pressure<<","<<volume<<","<<time<<","<<cycles<<","<<alarms<<"\n";
    return 0;
}
