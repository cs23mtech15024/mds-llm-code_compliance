// Context: Autonomous car brake response calibrator

#include <iostream>
int main(){
    int delaySteps[4] = {1, 2, 3, 4}; // C: decimal constants
    int total = 0;
    for(int d : delaySteps) total += d;
    std::cout<<"Brake delay calibration total: "<<total<<std::endl;
    return 0;
}
