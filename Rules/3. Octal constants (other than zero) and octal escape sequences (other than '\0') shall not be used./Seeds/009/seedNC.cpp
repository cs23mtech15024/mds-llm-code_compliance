// Context: Automotive ECU diagnostic log saver

#include <iostream>
#include <fstream>
#include <sys/stat.h>
int main(){
    std::string fname="ecu_diagnostic.log";
    std::ofstream log(fname);
    int perm = 0640; // NC: octal constant 0640 = 416 decimal
    chmod(fname.c_str(), perm);
    log<<"ECU diagnostics start."<<std::endl;
    log.close();
    std::cout<<"Log created."<<std::endl;
    return 0;
}
