// Context: Network routing retry limit header

// seed_049_NC.h
#pragma once
int seed049_retry_limit = 5;
bool seed049_should_retry(int n) {
    return n < seed049_retry_limit;
}
