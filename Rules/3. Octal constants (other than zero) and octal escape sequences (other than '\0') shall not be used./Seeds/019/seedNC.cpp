// Context: Nuclear plant pressure sensor diagnostics

#include <iostream>
#include <fstream>
int main(){
    std::ofstream report("pressure.txt");
    char alert='\077'; // NC: octal escape \077 = '?'
    report<<"ALERT CHAR="<<alert<<std::endl;
    report.close();
    std::cout<<"Pressure report generated."<<std::endl;
    return 0;
}
