
#include <vector>
#include <thread>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Core/Layer.cpp"


class App {
public:

    App()
    {
        const auto numOfThreads = std::thread::hardware_concurrency();  
    }
    ~App()
    {

    }

    void setActiveLayer(Layer* layer)
    {
        m_layer = layer;
    }


    void run()
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

private:

    sf::RenderWindow    m_window;
    
    Layer* m_layer { nullptr };
    

};
