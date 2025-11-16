// Context: Weather station hourly readings

// Seed 081 — NC: hourly data decays to pointer
#include <iostream>
float compute_daily_average(float readings[]) { // NC
    return readings[0];
}
int main(){
    float hourly_temps[24] = {18.5F};
    std::cout << "avg=" << compute_daily_average(hourly_temps) << "\n";
    return 0;
}