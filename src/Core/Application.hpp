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

    // Core
    Layer*              m_layer { nullptr };

    // Rendering
    sf::RenderWindow    m_window;

    // Thread and Job System
    ThreadPool          m_threadPool;
    JobQueue            m_jobQueue;
};
