// Context: Surveillance camera configuration writer

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("camera.cfg");
    int fps = 24; // C: decimal equivalent of 030
    int brightness = 61; // C: decimal equivalent of 075
    cfg<<"FPS="<<fps<<"\n"<<"BRIGHTNESS="<<brightness<<"\n";
    cfg.close();
    std::cout<<"Camera config saved."<<std::endl;
    return 0;
}
