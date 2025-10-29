// Context: Readonly results file via fchmod

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdio>
int main(){
    int fd = open("results.txt", O_WRONLY|O_CREAT|O_TRUNC, 420); // C: decimal
    if(fd<0){ perror("open"); return 1; }
    fchmod(fd, 292); // C: decimal equivalent of 0444
    write(fd, "done\n", 5);
    close(fd);
    std::cout<<"Results written."<<std::endl;
    return 0;
}
