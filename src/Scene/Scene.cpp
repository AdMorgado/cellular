#include "Scene/Scene.hpp"

#include "Scene/Entity.hpp"

Entity Scene::addEntity()
{
    Entity entity(m_registry.create(), this);

    return entity;
}

