// Context: Power grid substation status formatter

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("status.txt");
    char colon=':'; // C: direct literal
    log<<"VOLTAGE"<<colon<<"230V"<<std::endl;
    log.close();
    std::cout<<"Status formatted."<<std::endl;
    return 0;
}
