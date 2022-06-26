#pragma once

#include <SFML/Graphics.hpp>

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

struct Sprite {
    sf::Texture*    texture;
    sf::Vertex      vertices[4];

    void setTexture(sf::Texture* texture) {
        if(!texture) 
            return;

        sf::Vector2f size(texture->getSize().x, texture->getSize().y);

        vertices[0].position = sf::Vector2f(0.f,    0.f);
        vertices[1].position = sf::Vector2f(size.x, 0.f);
        vertices[2].position = sf::Vector2f(size.x, size.y);
        vertices[3].position = sf::Vector2f(0.f,    size.y);
    }

    void setColor(const sf::Color& color) {
        vertices[0].color = color;
        vertices[1].color = color;
        vertices[2].color = color;
        vertices[3].color = color;
    }
};