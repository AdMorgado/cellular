#pragma once

#include <vector>

#include <SFML/Graphics/RenderTarget.hpp>

#include "entt/entt.hpp"

#include "Scene/System.hpp"

class Entity;

class Scene
{
public:

    Scene();
    ~Scene();

    Entity addEntity();

    void update();
    void render(sf::RenderTarget& target) const;

    template<SystemConcept T>
    void addSystem()
    {
        m_systems.push_back(new T);
    }

private:

    std::vector<System*>    m_systems;
    entt::registry          m_registry;

    friend System;
    friend Entity;
};


