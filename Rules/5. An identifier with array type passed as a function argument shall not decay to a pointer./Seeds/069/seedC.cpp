// Context: IMU orientation quaternions

// Seed 069 — C: quaternion array by reference
#include <iostream>
void normalize_quaternion(float (&quat)[4]) { // C
    quat[0] = quat[0] / 2.0F;
    std::cout << "q0=" << quat[0] << "\n";
}
int main(){
    float imu_quat[4] = {1.0F, 0.0F, 0.0F, 0.0F};
    normalize_quaternion(imu_quat);
    return 0;
}