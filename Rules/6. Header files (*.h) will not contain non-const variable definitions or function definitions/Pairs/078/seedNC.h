// Context: Warehouse barcode scanner retry config

// seed_078_NC.h
#pragma once
int seed078_max_retries = 4;
bool seed078_allow_retry(int c) {
    return c < seed078_max_retries;
}
