// Context: Log writer with escaped header chars

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("hdr.log");
    char a='\123', b='\101'; // NC: octal escapes \123='S', \101='A'
    log<<a<<b<<" - start"<<"\n";
    log.close();
    std::cout<<"Header written."<<std::endl;
    return 0;
}
