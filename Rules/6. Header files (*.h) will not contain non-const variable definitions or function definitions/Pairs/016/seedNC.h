// Context: Medical device alarm thresholds

// seed_016_NC.h
#pragma once
// NC: thresholds defined and check function in header
float seed016_hr_threshold = 120.0F; // NC

bool seed016_is_alarm(float hr) { // NC
    return hr > seed016_hr_threshold;
}
