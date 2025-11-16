// Context: Robotic joint angle commands

// Seed 061 — C: joint angles by reference
#include <iostream>
void set_joint_angles(float (&angles)[6]) { // C
    angles[0] = 30.0F;
    std::cout << "joint0=" << angles[0] << "\n";
}
int main(){
    float robot_joints[6] = {0};
    set_joint_angles(robot_joints);
    return 0;
}