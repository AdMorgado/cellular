#pragma once

#include "entt/entt.hpp"

class Scene;

class Entity
{
public:
    Entity() = delete;
    Entity(entt::entity handle, Scene* scene) :
        m_handle(handle),
        m_scene(scene)
    {

    }

private:

    entt::entity    m_handle    { entt::null };
    Scene*          m_scene     { nullptr }; 

};

