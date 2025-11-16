// Context: Touchscreen calibration points

// Seed 024 — NC: calibration points decay to pointer
#include <iostream>
void calibrate_touch(int cal_points[]) { // NC
    cal_points[0] = 100;
    std::cout << "point0_x=" << cal_points[0] << "\n";
}
int main(){
    int touch_cal[6] = {0};
    calibrate_touch(touch_cal);
    return 0;
}