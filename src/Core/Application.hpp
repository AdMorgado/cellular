#pragma once

#include <vector>
#include <thread>
#include <memory>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Core/Layer.hpp"

#include "Threads/JobQueue.hpp"
#include "Threads/ThreadPool.hpp"

class App {
public:
    App(std::unique_ptr<Layer> layer);
    ~App();

    void run();

private:

    void handleEvents();
    void update(sf::Time dt);
    void render();

private:

    // Core
    std::unique_ptr<Layer>  m_layer;
    sf::RenderWindow        m_window;
    ThreadPool              m_threadPool;
};
