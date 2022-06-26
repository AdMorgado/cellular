#pragma once 

#include <type_traits>
#include <concepts>

#include <SFML/Graphics/RenderTarget.hpp>

class Scene;

class System
{
public:
    System() { }
    virtual ~System() {}

    virtual void start(Scene& scene) { }
    virtual void update(Scene& scene) { }
    virtual void render(const Scene& scene, sf::RenderTarget& target) const { }
};

template <typename T>
concept SystemConcept = std::is_base_of<System, T>::value;


