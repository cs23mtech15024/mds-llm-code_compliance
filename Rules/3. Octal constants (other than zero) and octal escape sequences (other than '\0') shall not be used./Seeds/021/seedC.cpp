// Context: Space rover motor current logger

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("current.log");
    char delim=' '; // C: use literal space instead of octal escape
    log<<"MOTOR"<<delim<<"CURRENT"<<std::endl;
    log.close();
    std::cout<<"Current log written."<<std::endl;
    return 0;
}
