// Context: Car infotainment audio buffer size header

// seed_061_NC.h
#pragma once
int seed061_audio_buffer = 2048;
int seed061_half_buffer() {
    return seed061_audio_buffer / 2;
}
