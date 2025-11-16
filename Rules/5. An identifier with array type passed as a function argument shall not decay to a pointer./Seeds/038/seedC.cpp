// Context: Flow meter volume readings

// Seed 038 — C: volume readings by reference
#include <iostream>
float calculate_total_flow(float (&volumes)[12]) { // C
    return volumes[0] + volumes[1];
}
int main(){
    float flow_volumes[12] = {10.5F, 11.2F};
    std::cout << "total_volume=" << calculate_total_flow(flow_volumes) << "\n";
    return 0;
}