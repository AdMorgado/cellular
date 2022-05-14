#include <Core/Application.hpp>

#include "Threads/ThreadPool.hpp"

#include <chrono>
#include <iostream>


App::App()
{
    const auto numOfThreads = std::thread::hardware_concurrency(); 
    m_threadPool.createThreads( [](){std::this_thread::sleep_for(std::chrono::milliseconds(100));} , 2);
}

App::~App()
{
    m_threadPool.shutdown();
}

void App::setActiveLayer(Layer* layer)
{
    if(!layer) return;
    
    m_layer = layer;
    m_layer->start();
}


void App::run()
{
    m_window.create(sf::VideoMode(960, 640), "cellular");
    m_window.setFramerateLimit(60);

    bool isRunning = true;
    sf::Clock internalClock;
    while(isRunning)
    {
        // Input
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                isRunning = false;
        }

        // Update
        if(m_layer)
        {
            const float deltaTime = internalClock.restart().asSeconds();
            m_layer->update(deltaTime);

            m_layer->render(m_window);
        }


        m_window.display();            
    }

    m_window.close();
}