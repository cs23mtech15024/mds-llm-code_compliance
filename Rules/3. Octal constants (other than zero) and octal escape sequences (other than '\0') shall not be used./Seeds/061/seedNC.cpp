// Context: Power grid substation status formatter

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("status.txt");
    char colon='\072'; // NC: octal escape \072 = ':'
    log<<"VOLTAGE"<<colon<<"230V"<<std::endl;
    log.close();
    std::cout<<"Status formatted."<<std::endl;
    return 0;
}
