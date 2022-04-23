#pragma once

#include <concepts>

#include <SFML/System/Vector2.hpp>

struct Transform
{
    sf::Vector2f    position    {0.f, 0.f};
    double          rotation    {0.f};
    sf::Vector2f    scale       {1.f, 1.f};
};

