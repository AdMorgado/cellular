#pragma once 

#include <type_traits>
#include <concepts>

#include <SFML/Graphics/RenderTarget.hpp>

#include <entt/entt.hpp>

class Scene;

class System
{
public:
    System() { }
    virtual ~System() {}

    virtual void start(Scene& scene) { }
    virtual void update(Scene& scene) { }
    virtual void render(const Scene& scene, sf::RenderTarget& target) const { }

protected:
    entt::registry& getRegistry(Scene& scene) {
        return scene.m_registry;
    }
};

template <typename T>
concept SystemConcept = std::is_base_of<System, T>::value;


