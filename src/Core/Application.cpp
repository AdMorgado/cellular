#include <Core/Application.hpp>

#include "Threads/ThreadPool.hpp"

#include <chrono>
#include <iostream>


App::App()
{
    const auto numOfThreads = std::thread::hardware_concurrency(); 
    m_threadPool.createThreads([&jobQueue = m_jobQueue](){
        
        }, numOfThreads);
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


void App::run() {
    m_window.create(sf::VideoMode(960, 640), "cellular");
    m_window.setFramerateLimit(60);

    bool isRunning = true;
    sf::Clock internalClock;
    while(isRunning) {
        // Input
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                isRunning = false;
        }

        const float deltaTime = internalClock.restart().asSeconds();
        
        // Update
        if(m_layer) {
            m_layer->update(deltaTime);
        }
        
        m_window.clear();

        if(m_layer) {
            m_layer->render(m_window);
        }

        m_window.display();            
    }

    m_window.close();
}