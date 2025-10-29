// Context: Space rover motor current logger

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("current.log");
    char delim='\040'; // NC: octal escape \040 = space
    log<<"MOTOR"<<delim<<"CURRENT"<<std::endl;
    log.close();
    std::cout<<"Current log written."<<std::endl;
    return 0;
}
