
#include "Core/Layer.hpp"
#include "Core/Application.hpp"

extern Layer* getLayer();

int main(int argc, char** argv)
{
    App app;

    Layer* layer = getLayer();

    app.setActiveLayer(layer);
    app.run();

    delete layer;

    return 0;
}
