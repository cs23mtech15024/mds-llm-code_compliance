// Context: Automated irrigation timer sequence

#include <iostream>
#include <array>
#include <thread>
#include <chrono>
int main(){
    std::array<int,4> times={010,020,030,040}; // NC: octal constants
    for(auto t:times){
        std::cout<<"Watering duration: "<<t<<"s"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
