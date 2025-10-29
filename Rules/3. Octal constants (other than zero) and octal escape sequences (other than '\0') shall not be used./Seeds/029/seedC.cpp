// Context: Network daemon umask initializer

#include <iostream>
#include <sys/stat.h>
int main(){
    mode_t old = umask(18); // C: decimal equivalent of 0022
    (void)old;
    std::cout<<"umask set."<<std::endl;
    return 0;
}
