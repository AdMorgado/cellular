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

        switch(event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::TextEntered:
                break;
            case sf::Event::KeyPressed:
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
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
