#pragma once

#include <concepts>

#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics/Transform.hpp>

struct Transform
{
    sf::Vector2f    position    {0.f, 0.f};
    double          rotation    {0.f};
    sf::Vector2f    scale       {1.f, 1.f};

    sf::Transform getTransform() const
    {
        float angle  = rotation * (3.141592654f / 180.f);
        float cosine = std::cos(angle);
        float sine   = std::sin(angle);
        float sxc    = scale.x * cosine;
        float syc    = scale.y * cosine;
        float sxs    = scale.x * sine;
        float sys    = scale.y * sine;
        float tx     = position.x;
        float ty     = position.y;

        sf::Transform transform = sf::Transform( sxc, sys, tx,
                                                -sxs, syc, ty,
                                                0.f, 0.f, 1.f);
        return transform;
    }
};

