// Context: Filesystem path length limits header

// seed_017_NC.h
#pragma once
// NC: max path length defined and helper implemented
int seed017_max_path = 260; // NC

bool seed017_too_long(const char* p) { // NC
    int len = 0; while(p && p[len]) ++len; return len > seed017_max_path;
}
