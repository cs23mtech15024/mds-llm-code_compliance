// Context: Glucose monitor trend data

// Seed 085 — NC: glucose readings decay to pointer
#include <iostream>
float analyze_glucose_trend(float readings[]) { // NC
    return (readings[1] - readings[0]);
}
int main(){
    float glucose_log[288] = {95.0F, 98.0F};
    std::cout << "delta=" << analyze_glucose_trend(glucose_log) << "\n";
    return 0;
}