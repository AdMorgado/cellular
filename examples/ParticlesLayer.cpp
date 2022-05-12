
#include <Cellular.hpp>

struct Particle
{
    float radius {1.f};
};

struct ParticleSystem : public System
{
    virtual void update() override
    {

    }
};

struct ParticleRendererSystem : public System
{
    virtual void render(sf::RenderTarget& target) const override
    {
        m_scene->m_registry;
    }
};

class ParticlesLayer : public Layer 
{
public:
    virtual void start() override
    {

    }

    virtual void update(const float dt) override
    {

    }

    virtual void render(sf::RenderTarget& target) const override
    {
        m_scene.render(target);
    }

private:

    Scene m_scene;

};

Layer* getLayer() 
{
    return new ParticlesLayer();
}

