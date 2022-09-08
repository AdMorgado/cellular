
#include <Cellular.hpp>

#include <mutex>
#include <thread>

struct Particle {
    sf::Vector2f velocity   {0.f, 0.f};
    float radius            {1.f};
};

class ParticlesLayer : public Layer {
public:
    ParticlesLayer() {
        
    }
    virtual ~ParticlesLayer() {
        
    }

    virtual void start() override {
        
        
    }

    virtual void update(std::function<void(Job*)> dispatchJob, const float dt) override {

    }

    virtual void render(sf::RenderTarget& target) override {

    }

    virtual void renderUI() override {
        
    }

    virtual void handleEvent(const sf::Event& event) override {

    }

private:
    sf::Sprite shape;
};

Layer* getLayer() {
    return new ParticlesLayer();
}

