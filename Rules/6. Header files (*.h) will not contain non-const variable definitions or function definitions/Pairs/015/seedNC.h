// Context: Printer spooler job queue defaults

// seed_015_NC.h
#pragma once
// NC: default queue depth and helper in header
int seed015_default_queue = 10; // NC

int seed015_enqueue_limit() { // NC
    return seed015_default_queue - 1;
}
