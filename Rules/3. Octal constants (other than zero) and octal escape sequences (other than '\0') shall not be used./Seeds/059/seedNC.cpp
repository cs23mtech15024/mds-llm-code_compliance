// Context: LIDAR point cloud resolution setter

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("lidar.conf");
    int resolution = 01000; // NC: octal constant 01000 = 512
    cfg<<"RESOLUTION="<<resolution<<std::endl;
    cfg.close();
    std::cout<<"LIDAR configured."<<std::endl;
    return 0;
}
