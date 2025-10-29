// Context: Server log file permission handler

#include <iostream>
#include <sys/stat.h>
#include <fstream>
int main(){
    std::ofstream f("server.log");
    int mode = 420; // C: decimal equivalent of 0644
    chmod("server.log", mode);
    f<<"Server initialized."<<std::endl;
    f.close();
    std::cout<<"Server log created."<<std::endl;
    return 0;
}
