
#include <Cellular.hpp>

#include <iostream>

struct Particle
{
    sf::Vector2f velocity   {0.f, 0.f};
    float radius            {1.f};
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

    }
};

class ParticlesLayer : public Layer 
{
public:
    virtual void start() override
    {


    }
    int i = 0;
    virtual void update(std::function<void(Job*)> dispatchJob, const float dt) override
    {

        Job job([&i = i](){
            std::cout << "Ligma: " << i++ << std::endl;
        });
        dispatchJob(&job);

        job.join();
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

