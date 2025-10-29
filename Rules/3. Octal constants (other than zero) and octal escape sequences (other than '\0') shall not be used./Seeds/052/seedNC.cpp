// Context: Telecom signal field separator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream f("signal.dat");
    char sep='\174'; // NC: octal escape \174 = '|'
    f<<"SIGNAL"<<sep<<"QUALITY"<<std::endl;
    f.close();
    std::cout<<"Signal file written."<<std::endl;
    return 0;
}
