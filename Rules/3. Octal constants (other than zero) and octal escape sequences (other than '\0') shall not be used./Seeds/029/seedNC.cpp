// Context: Network daemon umask initializer

#include <iostream>
#include <sys/stat.h>
int main(){
    mode_t old = umask(0022); // NC: octal constant 0022 = 18 decimal
    (void)old;
    std::cout<<"umask set."<<std::endl;
    return 0;
}
