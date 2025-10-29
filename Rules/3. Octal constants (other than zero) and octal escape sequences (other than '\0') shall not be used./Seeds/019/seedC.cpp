// Context: Nuclear plant pressure sensor diagnostics

#include <iostream>
#include <fstream>
int main(){
    std::ofstream report("pressure.txt");
    char alert='\x3F'; // C: hex escape \x3F = '?'
    report<<"ALERT CHAR="<<alert<<std::endl;
    report.close();
    std::cout<<"Pressure report generated."<<std::endl;
    return 0;
}
