// Context: Touchscreen calibration points

// Seed 024 — C: calibration points by reference
#include <iostream>
void calibrate_touch(int (&cal_points)[6]) { // C
    cal_points[0] = 100;
    std::cout << "point0_x=" << cal_points[0] << "\n";
}
int main(){
    int touch_cal[6] = {0};
    calibrate_touch(touch_cal);
    return 0;
}