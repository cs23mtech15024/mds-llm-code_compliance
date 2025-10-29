// Context: Readonly results file via fchmod

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdio>
int main(){
    int fd = open("results.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644); // NC: 0644 = 420
    if(fd<0){ perror("open"); return 1; }
    fchmod(fd, 0444); // NC: octal 0444 = 292 decimal
    write(fd, "done\n", 5);
    close(fd);
    std::cout<<"Results written."<<std::endl;
    return 0;
}
