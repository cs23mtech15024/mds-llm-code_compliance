// Context: LIDAR distance measurements

// Seed 015 — NC: distance array decays to pointer
#include <iostream>
float find_minimum_distance(float distances[]) { // NC
    return distances[0];
}
int main(){
    float lidar_data[360] = {5.5F, 6.2F, 4.8F};
    std::cout << "min_dist=" << find_minimum_distance(lidar_data) << "\n";
    return 0;
}