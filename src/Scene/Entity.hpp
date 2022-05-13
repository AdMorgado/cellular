#pragma once

#include "entt/entt.hpp"

#include "Scene/Scene.hpp"

class Entity
{
public:
    Entity() = default;
    Entity(entt::entity handle, Scene* scene) :
        m_handle(handle),
        m_scene(scene)
    {

    }
    Entity(Entity& other) = default;

    template <typename T>
    T& addComponent()
    {
        return m_scene->m_registry.emplace<T>(m_handle);
    }

    template <typename T>
    T* getComponent()
    {
        return m_scene->m_registry.try_get<T>(m_handle);
    }

    template <typename T>
    bool hasComponent()
    {
        return m_scene->m_registry.try_get<T>(m_handle) != nullptr;
    }

    template <typename T>
    bool removeComponent()
    {
        return m_scene->m_registry.remove<T>(m_handle);
    }



private:

    entt::entity    m_handle    { entt::null };
    Scene*          m_scene     { nullptr }; 

};

