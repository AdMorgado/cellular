#pragma once

#include <math.h>

constexpr double PI = 3.14159265358979323846;

constexpr inline double degToRad(double& degrees) noexcept {
    return degrees * (PI / 180.0);
}

constexpr inline double radToDeg(double& radians) noexcept {
    return radians * (180.0 / PI); 
}
