#include "Scene/Scene.hpp"

#include "Scene/Entity.hpp"
#include "Scene/Component.hpp"

Scene::Scene()
{

}

Scene::~Scene()
{

}


Entity Scene::addEntity()
{
    Entity entity(m_registry.create(), this);
    entity.addComponent<Transform>();
    return entity;
}


