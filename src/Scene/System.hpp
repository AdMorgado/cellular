#pragma once 

#include <type_traits>
#include <concepts>

#include <SFML/Graphics/RenderTarget.hpp>

class Scene;

class System
{
public:

    System(Scene* scene) : 
        m_scene(scene)
    {

    }
    virtual ~System() {}

    virtual void start() {};
    virtual void update() {};
    virtual void render(sf::RenderTarget& target) const {};

protected:

    Scene*      m_scene;

};

template <typename T>
concept SystemConcept = std::is_base_of<System, T>::value;


