// Context: Weather station hourly readings

// Seed 081 — C: hourly data by reference
#include <iostream>
float compute_daily_average(float (&readings)[24]) { // C
    return readings[0];
}
int main(){
    float hourly_temps[24] = {18.5F};
    std::cout << "avg=" << compute_daily_average(hourly_temps) << "\n";
    return 0;
}