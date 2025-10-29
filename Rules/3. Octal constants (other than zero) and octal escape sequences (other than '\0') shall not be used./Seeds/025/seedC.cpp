// Context: Secure service PID file creation

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdio>
int main(){
    const char* pidfile = "/tmp/service.pid";
    int mode = 384; // C: decimal equivalent of 0600
    int fd = open(pidfile, O_WRONLY|O_CREAT|O_TRUNC, mode);
    if(fd < 0){ perror("open"); return 1; }
    const char* pid = "12345\n";
    write(fd, pid, 6);
    close(fd);
    std::cout<<"PID file created with mode="<<mode<<"\n";
    return 0;
}
