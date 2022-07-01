#pragma once

#include <vector>

#include <SFML/Graphics/RenderTarget.hpp>

#include "entt/entt.hpp"

class System;
class Entity;

class Scene
{
public:
    Scene();
    ~Scene();

    Entity addEntity();

private:
    entt::registry m_registry;

    friend System;
    friend Entity;
};


