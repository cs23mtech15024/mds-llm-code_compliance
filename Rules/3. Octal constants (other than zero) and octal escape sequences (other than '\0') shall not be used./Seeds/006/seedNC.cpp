// Context: Drone telemetry file output

#include <iostream>
#include <fstream>
int main(){
    std::ofstream tlog("telemetry.dat");
    tlog<<'\123'<<std::endl; // NC: octal escape \123 = 'S'
    tlog.close();
    std::cout<<"Telemetry character logged."<<std::endl;
    return 0;
}
