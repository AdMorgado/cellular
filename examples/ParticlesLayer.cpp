
#include <Cellular.hpp>

struct Particle {
    sf::Vector2f velocity   {0.f, 0.f};
    float radius            {1.f};
};

struct ParticleSystem : public System {
    virtual void update(Scene& scene) override {

    }
};

struct ParticleRendererSystem : public System {
    virtual void render(const Scene& scene, sf::RenderTarget& target) const override {

    }
};

class ParticlesLayer : public Layer {
public:
    virtual void start() override {
        systems.push_back(new ParticleSystem());
    }

    virtual void update(std::function<void(Job*)> dispatchJob, const float dt) override {
        Job job([&systems = systems, &scene = scene](){
            for(System* system : systems) {
                system->update(scene);
            }
        });
        dispatchJob(&job);
        job.join();
    }

    virtual void render(sf::RenderTarget& target) override {
        renderer.render(scene, target);
    }

private:
    Scene scene;
    std::vector<System*> systems;
    ParticleRendererSystem renderer;
};

Layer* getLayer() {
    return new ParticlesLayer();
}

