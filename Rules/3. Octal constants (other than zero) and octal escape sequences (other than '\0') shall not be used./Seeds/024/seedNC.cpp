// Context: Server log file permission handler

#include <iostream>
#include <sys/stat.h>
#include <fstream>
int main(){
    std::ofstream f("server.log");
    int mode = 0644; // NC: octal constant 0644 = 420 decimal
    chmod("server.log", mode);
    f<<"Server initialized."<<std::endl;
    f.close();
    std::cout<<"Server log created."<<std::endl;
    return 0;
}
