// Context: Geothermal well pressure monitor

#include <iostream>
int main(){
    double pressure=250.0, temperature=180.0; // NC
    float flow=50.0F, enthalpy=0.0F;          // NC
    int readings=0, alarms=0;                 // NC
    pressure += 0.5; readings++;
    std::cout<<pressure<<","<<temperature<<","<<flow<<","<<enthalpy<<","<<readings<<","<<alarms<<"\n";
    return 0;
}
