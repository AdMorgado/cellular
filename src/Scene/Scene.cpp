#include "Scene/Scene.hpp"

#include "Scene/Entity.hpp"
#include "Scene/Component.hpp"

Scene::Scene()
{

}

Scene::~Scene()
{
    for(auto& system : m_systems)   
        delete system;

    m_systems.clear();
}


Entity Scene::addEntity()
{
    Entity entity(m_registry.create(), this);
    entity.addComponent<Transform>();
    return entity;
}

void Scene::update()
{

}

void Scene::render(sf::RenderTarget& target) const
{
    for(auto& system : m_systems)
    {
        system->render(target);
    }
}



