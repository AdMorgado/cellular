#pragma once

#include <vector>

#include "entt/entt.hpp"

class Entity;

class Scene
{
public:

    Entity addEntity();

private:

    entt::registry  m_registry;

};


