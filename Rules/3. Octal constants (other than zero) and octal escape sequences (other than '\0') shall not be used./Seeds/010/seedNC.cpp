// Context: Surveillance camera configuration writer

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("camera.cfg");
    int fps = 030; // NC: octal constant 030 = 24 decimal
    int brightness = 075; // NC: octal constant 075 = 61 decimal
    cfg<<"FPS="<<fps<<"\n"<<"BRIGHTNESS="<<brightness<<"\n";
    cfg.close();
    std::cout<<"Camera config saved."<<std::endl;
    return 0;
}
