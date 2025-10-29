// Context: Rail crossing light pattern configuration

#include <iostream>
#include <thread>
#include <chrono>
int main(){
    int pattern[3]={8,16,24}; // C: decimal equivalents
    for(int t:pattern){
        std::cout<<"Blink for "<<t<<" sec"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
