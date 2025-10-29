// Context: Log writer with escaped header chars

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("hdr.log");
    char a='\x53', b='\x41'; // C: hex escapes \x53='S', \x41='A'
    log<<a<<b<<" - start"<<"\n";
    log.close();
    std::cout<<"Header written."<<std::endl;
    return 0;
}
