#pragma once

#include <vector>
#include <thread>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Core/Layer.hpp"

#include "Threads/ThreadPool.hpp"

class App {
public:
    App();
    ~App();

    void setActiveLayer(Layer* layer);

    void run();

private:
    sf::RenderWindow    m_window;
    Layer*              m_layer { nullptr };
    ThreadPool          m_threadPool;
};
