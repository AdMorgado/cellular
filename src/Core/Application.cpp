#include <Core/Application.hpp>

#include "Threads/ThreadPool.hpp"

App::App()
{
    const auto numOfThreads = std::thread::hardware_concurrency(); 
    startThreadPool(numOfThreads-1);
}

App::~App()
{
    stopThreadPool();
}

void App::setActiveLayer(Layer* layer)
{
    m_layer = layer;
}


void App::run()
{
    m_window.create(sf::VideoMode(960, 640), "cellular");

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
            m_layer->update();
        }

        // Render
        m_window.clear();

        m_window.display();            
    }
}