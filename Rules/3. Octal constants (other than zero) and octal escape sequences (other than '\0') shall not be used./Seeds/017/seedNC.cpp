// Context: Security door keypad tone generator

#include <iostream>
#include <thread>
#include <chrono>
int main(){
    int tones[3] = {0110, 0120, 0130}; // NC: octal constants (0110=72, 0120=80, 0130=88)
    for(int t : tones){
        std::cout<<"Tone frequency: "<<t<<"Hz"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
