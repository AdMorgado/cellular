#pragma once

#include <iostream>
#include <functional>

#include <SFML/Graphics/RenderTarget.hpp>

#include "Threads/Job.hpp"

class Layer
{
public:
    Layer() = default;
    virtual ~Layer() = default;

    virtual void start() = 0;
    virtual void update(std::function<void(Job*)> jobDispatcher, const float dt) = 0;
    virtual void render(sf::RenderTarget& target) const = 0;
};

