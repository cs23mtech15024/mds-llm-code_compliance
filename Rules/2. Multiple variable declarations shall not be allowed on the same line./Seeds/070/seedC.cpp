// Context: Dialysis machine flow regulator

#include <iostream>
int main(){
    float flowRate=200.0F; // C
    float pressure=0.0F;   // C
    double volume=0.0;     // C
    double time=0.0;       // C
    unsigned cycles=0U;    // C
    unsigned alarms=0U;    // C
    flowRate += 1.0F; cycles++;
    std::cout<<flowRate<<","<<pressure<<","<<volume<<","<<time<<","<<cycles<<","<<alarms<<"\n";
    return 0;
}
