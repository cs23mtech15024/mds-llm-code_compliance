// Context: Security door keypad tone generator

#include <iostream>
#include <thread>
#include <chrono>
int main(){
    int tones[3] = {72, 80, 88}; // C: decimal equivalents
    for(int t : tones){
        std::cout<<"Tone frequency: "<<t<<"Hz"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
