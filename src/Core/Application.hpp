#pragma once

#include <vector>
#include <thread>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Core/Layer.hpp"

#include "Threads/JobQueue.hpp"
#include "Threads/ThreadPool.hpp"

class App {
public:
    App();
    ~App();

    void setActiveLayer(Layer* layer);

    void run();

private:

    void handleEvents();
    void update(sf::Time dt);
    void render();

private:

    // Core
    Layer*              m_layer { nullptr };

    sf::RenderWindow    m_window;
    
    ThreadPool          m_threadPool;
};
