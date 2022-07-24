#include <Core/Application.hpp>


#include <chrono>
#include <string>
#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

App::App() : 
    m_threadPool(std::thread::hardware_concurrency()) {
}

App::~App() {
    m_threadPool.shutdown();
}

void App::setActiveLayer(Layer* layer) {
    if(!layer) return;

    m_layer = layer;
    m_layer->start();
}


void App::run() {
    m_window.create(sf::VideoMode(960, 640), "cellular");
    m_window.setFramerateLimit(60);

    ImGui::SFML::Init(m_window);

    bool isRunning = true;
    sf::Clock internalClock;
    while(isRunning) {
        // Input
        sf::Event event;
        while (m_window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(m_window, event);

            if (event.type == sf::Event::Closed)
                isRunning = false;
        }
        const sf::Time dt = internalClock.restart();
        const float deltaTime = dt.asSeconds();
        ImGui::SFML::Update(m_window, dt);

        // Update
        if(m_layer) {
            m_layer->update([&pool = m_threadPool](Job* job) {
                pool.execute(job);
            }, deltaTime);
        }

        // Render
        m_window.clear();
        if(m_layer) {
            m_layer->render(m_window);
            m_layer->renderUI();
        }

        ImGui::SFML::Render(m_window);
        m_window.display();
    }

    m_window.close();
    ImGui::SFML::Shutdown();
}