#include <Core/Application.hpp>


#include <chrono>
#include <string>
#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include "Core/Resource.hpp"

App::App(std::unique_ptr<Layer> layer) : 
    m_layer(std::move(layer)),
    m_threadPool(std::thread::hardware_concurrency()) {

    Resource::loadResources();

    m_layer->start();
}

App::~App() {
    m_threadPool.shutdown();
}

void App::run() {
    m_window.create(sf::VideoMode(960, 640), "cellular");
    m_window.setFramerateLimit(60);

    if(!ImGui::SFML::Init(m_window)) 
        throw std::runtime_error("ImGui::SFML::Init() has failed");

    sf::Clock internalClock;
    while(m_window.isOpen()) {
        // Input
        handleEvents();

        update(internalClock.restart());

        render();
    }

    ImGui::SFML::Shutdown();
}

void App::handleEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(m_window, event);
        if(m_layer) m_layer->handleEvent(event);
        switch(event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height)));
                break;
            default:
                break;
        }
    }
}

void App::update(sf::Time dt) {
    
    ImGui::SFML::Update(m_window, dt);
    
    const float deltaTime = dt.asSeconds();

    if(m_layer) {
        m_layer->update([&pool = m_threadPool](Job* job) {
            pool.execute(job);
        }, deltaTime);
    }
}

void App::render() {
    m_window.clear();
    if(m_layer) {
        m_layer->render(m_window);
        m_layer->renderUI();
    }

    ImGui::SFML::Render(m_window);
    m_window.display();
}
