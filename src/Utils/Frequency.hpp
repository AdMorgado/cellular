#pragma once

#include <cassert>
#include <stdint.h>
#include <exception>
#include <SFML/System/Clock.hpp>

class FrequencyCounter {
public:

    void update() {
        frames++;
    }

    float get() {
        const float elapsed = clock.restart().asSeconds();
        assert(elapsed != 0);
        const float fps = frames / elapsed;
        frames = 0;
        return fps;
    }

private:
    sf::Clock   clock;
    uint32_t    frames;
};

