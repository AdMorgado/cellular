
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
        
        std::lock_guard<std::mutex> lock(guard);
        shape.setTexture(Resource::getTexture("textures/circle.png"));
        
    }

    virtual void update(std::function<void(Job*)> dispatchJob, const float dt) override {
        Job job([&shape = shape, &guard = guard, dt]{
            std::lock_guard<std::mutex> lock(guard);
            sf::Vector2f move;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move += sf::Vector2f( 0.f, -1.f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move += sf::Vector2f( 0.f,  1.f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move += sf::Vector2f(-1.f,  0.f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move += sf::Vector2f( 1.f,  0.f);

            shape.move(move * dt * 150.f);
        });
        job.join();
    }

    virtual void render(sf::RenderTarget& target) override {
        std::lock_guard<std::mutex> lock(guard);
        target.draw(shape);

        sf::Text text;
        text.setFont(Resource::getFont("fonts/ProggyClean.ttf"));
        text.setString("dsfgerg");
        text.setPosition(0.f, 0.f);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        target.draw(text);
    }

    virtual void renderUI() override {
        
    }

    virtual void handleEvent(const sf::Event& event) override {

    }

private:

    std::mutex guard;
    sf::Sprite shape;
};

Layer* getLayer() {
    return new ParticlesLayer();
}

