#pragma once

#include <random>

float random01()
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

float random(float min, float max)
{
    const float interval = max - min;

    return min + (random01() * interval);
}

