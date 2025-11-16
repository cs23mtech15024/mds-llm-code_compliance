// Context: Aviation fuel temperature compensation header

// seed_097_NC.h
#pragma once
float seed097_temp_coeff = -0.0021F;
float seed097_compensate(float t) {
    return 1.0F + (seed097_temp_coeff * t);
}
