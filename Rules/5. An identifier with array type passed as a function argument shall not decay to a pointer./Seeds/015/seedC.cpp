// Context: LIDAR distance measurements

// Seed 015 — C: distance array by reference
#include <iostream>
float find_minimum_distance(float (&distances)[360]) { // C
    return distances[0];
}
int main(){
    float lidar_data[360] = {5.5F, 6.2F, 4.8F};
    std::cout << "min_dist=" << find_minimum_distance(lidar_data) << "\n";
    return 0;
}