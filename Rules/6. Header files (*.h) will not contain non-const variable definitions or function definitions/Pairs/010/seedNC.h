// Context: Autonomous vehicle lane model parameters

// seed_010_NC.h
#pragma once
// NC: lane width & curvature formula inside header
float seed010_lane_width = 3.7F; // NC

float seed010_curvature(float r) { // NC
    return 1.0F / (r + seed010_lane_width);
}
