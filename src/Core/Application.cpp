#include <Core/Application.hpp>

#include "Threads/ThreadPool.hpp"

#include <iostream>

App::App()
{
    const auto numOfThreads = std::thread::hardware_concurrency(); 
    m_threadPool.createThreads(numOfThreads - 1);
}

App::~App()
{
    m_threadPool.stopThreads();
}

void App::setActiveLayer(Layer* layer)
{
    m_layer = layer;
}


void App::run()
{
    m_window.create(sf::VideoMode(960, 640), "cellular");

    sf::Clock internalClock;
    while(m_window.isOpen())
    {
        // Input
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        // Update
        if(m_layer)
        {
            const float deltaTime = internalClock.restart().asSeconds();
            m_layer->update(deltaTime);
        }

        // Render
        m_window.clear();

        m_window.display();            
    }
}