// Context: Machine vision ROI parameters header

// seed_018_NC.h
#pragma once
// NC: ROI dimensions and function implemented in header
int seed018_roi_width = 640; // NC
int seed018_roi_height = 480; // NC

int seed018_area() { // NC
    return seed018_roi_width * seed018_roi_height;
}
