// Context: Automated irrigation timer sequence

#include <iostream>
#include <array>
#include <thread>
#include <chrono>
int main(){
    std::array<int,4> times={8,16,24,32}; // C: decimal equivalents
    for(auto t:times){
        std::cout<<"Watering duration: "<<t<<"s"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
