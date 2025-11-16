// Context: IMU orientation quaternions

// Seed 069 — NC: quaternion array decays to pointer
#include <iostream>
void normalize_quaternion(float quat[]) { // NC
    quat[0] = quat[0] / 2.0F;
    std::cout << "q0=" << quat[0] << "\n";
}
int main(){
    float imu_quat[4] = {1.0F, 0.0F, 0.0F, 0.0F};
    normalize_quaternion(imu_quat);
    return 0;
}