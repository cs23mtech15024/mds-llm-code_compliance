// Context: Geothermal well pressure monitor

#include <iostream>
int main(){
    double pressure=250.0;     // C
    double temperature=180.0;  // C
    float flow=50.0F;          // C
    float enthalpy=0.0F;       // C
    int readings=0;            // C
    int alarms=0;              // C
    pressure += 0.5; readings++;
    std::cout<<pressure<<","<<temperature<<","<<flow<<","<<enthalpy<<","<<readings<<","<<alarms<<"\n";
    return 0;
}
