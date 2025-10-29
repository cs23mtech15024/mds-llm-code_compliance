// Context: Drone telemetry file output

#include <iostream>
#include <fstream>
int main(){
    std::ofstream tlog("telemetry.dat");
    tlog<<'\x53'<<std::endl; // C: hex escape \x53 = 'S'
    tlog.close();
    std::cout<<"Telemetry character logged."<<std::endl;
    return 0;
}
