// Context: Smart lock retry timeout header

// seed_056_NC.h
#pragma once
int seed056_retry_timeout_ms = 3000;
bool seed056_timeout_expired(int elapsed) {
    return elapsed > seed056_retry_timeout_ms;
}
