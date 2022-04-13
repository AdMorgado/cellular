#pragma once

#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>

class Layer
{
public:

    virtual void start() = 0;
    virtual void update(const float dt) = 0;
    virtual void render(sf::RenderTarget& target) const = 0;

};

