// Context: LED diagnostic blink pattern controller

#include <iostream>
#include <thread>
#include <chrono>
int main(){
    int blinkPattern[3] = {01, 02, 03}; // NC: octal constants
    for(int i=0;i<3;i++){
        std::cout<<"LED ON for pattern="<<blinkPattern[i]<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 0;
}
