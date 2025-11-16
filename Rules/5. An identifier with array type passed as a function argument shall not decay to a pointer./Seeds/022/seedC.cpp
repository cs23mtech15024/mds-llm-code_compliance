// Context: Wind speed measurement samples

// Seed 022 — C: wind speed array by reference
#include <iostream>
float compute_wind_average(float (&speeds)[100]) { // C
    return (speeds[0] + speeds[1]) / 2.0F;
}
int main(){
    float wind_samples[100] = {5.5F, 6.0F};
    std::cout << "avg_speed=" << compute_wind_average(wind_samples) << "\n";
    return 0;
}