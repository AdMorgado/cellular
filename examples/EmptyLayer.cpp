#include "Cellular.hpp"

#include <iostream>

class EmptyLayer : public Layer
{
public:
    virtual void start() 
    {

    }
    virtual void update(const float dt) 
    {
        
    }
    virtual void render(sf::RenderTarget& target) const 
    {

    }
private:

};

Layer* getLayer()
{
    return new EmptyLayer();
}


